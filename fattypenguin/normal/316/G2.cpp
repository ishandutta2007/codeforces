#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

const int MAXN = 1001000;

int sa[MAXN],height[MAXN],rank[MAXN];
int wa[MAXN],wb[MAXN],wc[MAXN],wd[MAXN];

namespace SA
{

    bool cmp(int *r,int a,int b,int l,int n)
    {
        int la = r[a],lb = r[b],ra,rb;
        ra = a+l < n? r[a+l] : -1;
        rb = b+l < n? r[b+l] : -1;
        return (la == lb) && (ra == rb);
    }

    void makesa(char *r,int *sa,int n,int m)
    {
        int *x = wa,*y = wb;
        for (int i = 0;i < m;++i)
            wc[i] = 0;
        for (int i = 0;i < n;++i)
            ++wc[x[i] = r[i]];
        for (int i = 1;i < m;++i)
            wc[i] += wc[i-1];
        for (int i = n-1;i >= 0;--i)
            sa[--wc[x[i]]] = i;
        for (int tot = 0,p = 1;tot+1 < n;p <<= 1,m = tot+1)
        {
            tot = 0;
            for (int i = n-p;i < n;++i)
                y[tot++] = i;
            for (int i = 0;i < n;++i)
                if (sa[i] >= p)
                    y[tot++] = sa[i] - p;
            for (int i = 0;i < n;++i)
                wd[i] = x[y[i]];
            for (int i = 0;i < m;++i)
                wc[i] = 0;
            for (int i = 0;i < n;++i)
                ++wc[wd[i]];
            for (int i = 1;i < m;++i)
                wc[i] += wc[i-1];
            for (int i = n-1;i >= 0;--i)
                sa[--wc[wd[i]]] = y[i];
            int *t = x; x = y; y = t;
            x[sa[0]] = tot = 0;
            for (int i = 1;i < n;++i)
                x[sa[i]] = cmp(y,sa[i-1],sa[i],p,n) ? tot : ++tot;
        }
    }

    void makeheight(char *r,int *sa,int *height,int n)
    {
        for (int i = 0;i < n;++i)
            rank[sa[i]] = i;
        height[0] = 0;
        for (int i = 0;i < n;++i)
        {
            if (!rank[i])
                continue;
            if (!i)
                height[rank[i]] = 0;
            else
                height[rank[i]] = height[rank[i-1]] - 1;
            if (height[rank[i]] < 0)
                height[rank[i]] = 0;
            for (;r[i+height[rank[i]]] == r[sa[rank[i]-1] + height[rank[i]]];++height[rank[i]]);
        }
    }
};

char s[MAXN], res[MAXN];
int which[MAXN], length[MAXN], begin[MAXN];
int low[MAXN], high[MAXN];

int longest[11][50007];
int num[11][50007];
int ptrl[11], ptrr[11];
int suml[11], sumr[11];
int top[11];

int main() {
	scanf("%s", s);
	length[0] = strlen(s);
	int len = 0;
	begin[0] = 0;
	REP(i, length[0]) {
		which[len] = 0;
		res[len++] = s[i];
	}
	which[len] = -1;
	res[len++] = '$';
	int n;
	cin >> n;
	REP(i, n) {
		scanf("%s", s);
		cin >> low[i + 1] >> high[i + 1];
		length[i + 1] = strlen(s);
		begin[i + 1] = len;
		REP(j, length[i + 1]) {
			which[len] = i + 1;
			res[len++] = s[j];
		}
		which[len] = -1;
		res[len++] = i + 1 + '$';
	}

    res[len] = 0;
    SA::makesa(res, sa, len, 200);
    SA::makeheight(res, sa, height, len);

    int all = 0;

    long long answer = 0;
    int lastLength = 0;
    height[len] = 0;
    // FILL(ptrl, -1);
    // FILL(ptrr, -1);
    for (int i = 0; i < len; ++i) {
    	// cout << (res + sa[i]) << endl;

    	for (int j = 1; j <= n; ++j) {
    		int sum = 0;
    		while (top[j] && height[i] <= longest[j][top[j] - 1]) {
    			sum += num[j][top[j] - 1];

    			if (ptrl[j] < top[j]) {
    				suml[j] -= num[j][top[j] - 1];
    			}

    			if (ptrr[j] < top[j]) {
    				sumr[j] -= num[j][top[j] - 1];
    			}

    			--top[j];
    		}
    	
    		ptrl[j] = min(ptrl[j], top[j] + 1);
    		ptrr[j] = min(ptrr[j], top[j] + 1);

    		if (height[i] > 0 && sum > 0) {
    			longest[j][top[j]] = height[i];
    			num[j][top[j]++] = sum;

    			if (ptrl[j] < top[j]) {
    				suml[j] += sum;
    			}
    			if (ptrr[j] < top[j]) {
    				sumr[j] += sum;
    			}

    			int index = j;

				while (ptrl[index] - 1 >= 0 && suml[index] < low[index]) {
					--ptrl[index];
					suml[index] += num[index][ptrl[index]];
				}

				while (ptrr[index] - 1 >= 0 && sumr[index] + num[index][ptrr[index] - 1] <= high[index]) {
					--ptrr[index];
					sumr[index] += num[index][ptrr[index]];
				}
    		} else {
    			ptrl[j] = min(ptrl[j], top[j]);
    			ptrr[j] = min(ptrr[j], top[j]);
    		}
    	}

    	// for (int j = 1; j <= n; ++j) {
    	// 	printf("ptrl[j] = %d, ptrr[j] = %d, top[j] = %d, suml[j] = %d, sumr[j] = %d\n", ptrl[j], ptrr[j],top[j], suml[j], sumr[j]);
    	// }

    	if (which[sa[i]] == 0) {
    		// assert( length[0] - (sa[i] - begin[0]) >= lastLength);
    		lastLength = length[0] - (sa[i] - begin[0]);
    //		all += lastLength;
    	}

    	if (which[sa[i]] == -1) {
    	} else if (which[sa[i]] == 0) {
    	} else {
    		int index = which[sa[i]];
    		// cout << "index = " << index << endl;
    		int shift = sa[i] - begin[index];
    		if (top[index] > 0 && longest[index][top[index] - 1] == length[index] - shift) {
    			++num[index][top[index] - 1];
    			if (ptrl[index] != top[index]) ++suml[index];
    			if (ptrr[index] != top[index]) ++sumr[index];
    		} else {
    			num[index][top[index]] = 1;
    			longest[index][top[index]++] = length[index] - shift;
    			++suml[index];
    			++sumr[index];
    		}

			while (ptrl[index] - 1 >= 0 && suml[index] < low[index]) {
				--ptrl[index];
				suml[index] += num[index][ptrl[index]];
			}

			while (ptrr[index] - 1 >= 0 && sumr[index] + num[index][ptrr[index] - 1] <= high[index]) {
				--ptrr[index];
				sumr[index] += num[index][ptrr[index]];
			}

    		while (ptrl[index] + 1 <= top[index] && suml[index] - num[index][ptrl[index]] >= low[index]) {
    			suml[index] -= num[index][ptrl[index]];
    			++ptrl[index];
    		}

    		while (ptrr[index] + 1 <= top[index] && sumr[index] > high[index]) {
    			sumr[index] -= num[index][ptrr[index]];
    			++ptrr[index];
    		}
    	}


    	if (height[i + 1] < lastLength) {
    		int minp = 1, maxp = 100000000;
    		for (int j = 1; j <= n; ++j) {
    			if (top[j] == 0) {
    				if (low[j] != 0) goto outer;
    			} else {
    				if (suml[j] >= low[j] && sumr[j] <= high[j] && ptrr[j] <= ptrl[j]) {
    					if (ptrl[j] < top[j]) {
    						maxp = min(maxp, longest[j][ptrl[j]]);
    					}

						if (ptrr[j] != 0) {
							minp = max(minp, longest[j][ptrr[j] - 1] + 1);
						}
    				} else {
    					goto outer;
    				}
    			}
    		}
    		if (minp <= maxp) {
    			minp = max(minp, height[i + 1] + 1);
    			maxp = min(maxp, lastLength);
    			// cout << "minp = " << minp << " maxp = " << maxp << endl;
    			if (minp <= maxp) answer += maxp - minp + 1;
    		}
   outer: ;
    		lastLength = height[i + 1];
    	}

    	// for (int j = 1; j <= n; ++j) {
    	// 	printf("ptrl[j] = %d, ptrr[j] = %d, top[j] = %d, suml[j] = %d, sumr[j] = %d\n", ptrl[j], ptrr[j],top[j], suml[j], sumr[j]);
    	// }
    }

    cout << answer << endl;

	return 0;
}