#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <cassert>
                   
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++) 
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = int(a); i < int(b); i++)

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;

const int INF = 1E9;   
const ld eps = 1e-7;
const int MAXN = 1048576 * 2;   
const int MAXM = 22;
                 
int n, m, i1, i2, n1, n2, len;
int a[MAXN], b[MAXN], p, q;
ll add, k, sum[MAXM], answer, cur[MAXM];
                       
int main() {

    cin >> n;
    //n = 20;
    len = 1 << n;

    //cout << len << endl;
    forn(i, len)
    	scanf("%d", &a[i]);
	sum[0] = 0;
	cur[0] = 0;
	answer = 0;
	for (int i = 1; i <= n; i++) {
		sum[i] = cur[i] = 0;

		int l = 1 << (i - 1);
		add = 1ll * l * l;

		k = 0;
		sum[i] = 0;
	
		for (int start = 0; start < len; start += l * 2) {
			i1 = start;
			i2 = start + l;
			n1 = start + l;
			n2 = start + 2 * l;
			p = 0;

			
			int j1, j2;
			while (i1 < n1 && i2 < n2) {
				if (a[i1] < a[i2]) {
					b[p] = a[i1];
					i1++;
					p++;
				} else if (a[i1] == a[i2]) {
					j1 = i1;
					j2 = i2;
					while (j1 < n1 && a[j1] == a[i2]) {
						j1++;
						b[p++] = a[i2];
					}
					j1--;
					while (j2 < n2 && a[j2] == a[i2]) {
						j2++;
						b[p++] = a[i2];
						cur[i] += n1 - j1 - 1;
					}
					j2--;

					//cout << i1 << ' ' << j1 << ' ' << i2 << ' ' << j2 << endl;

					sum[i] -= 1ll * (j1 - i1 + 1) * (j2 - i2 + 1);
					i1 = j1 + 1;
					i2 = j2 + 1;
				} else {
					b[p] = a[i2];
					i2++;
					p++;
					cur[i] += (n1 - i1);
				}	
			}
			while (i1 < n1) {
				b[p] = a[i1]; 
				i1++;
				p++;
			}
			while (i2 < n2) {
				b[p] = a[i2]; 
				i2++;
				p++;
			}	     
	        forn(i, l * 2) 
	        	a[start + i] = b[i];
	        
			k++;
		}

		//forn(j, len)
		//	cout << a[j] << ' ';
		//cout << endl;

		//cout << sum[i] << endl;
		sum[i] += add * k;
		answer += cur[i];
    }

    //forn(i, n + 1)
    //	cout << cur[i] << ' ' << sum[i] << endl;
    	 
    cin >> m;
    forn(i, m) {
    	scanf("%d", &q);
    	forab(j, 1, q + 1)
    		cur[j] = sum[j] - cur[j];

    	answer = 0;
    	forab(j, 1, n + 1)
    		answer += cur[j]; 
    	printf("%I64d\n", answer);	
	}
	                   
    return 0;
}