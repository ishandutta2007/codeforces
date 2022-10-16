#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

int arr[110000];
int sum[110000];
int best[110000];
pair<int, pii> query[110000];
int ans[110000];
int bs;

int get(int l) {
    int s = 0;
    while (l > 0) {
        s += sum[l];
        l -= l&-l;
    }
    return s;
}

void upd(int l, int v) {
    while (l <= 100010) {
        sum[l] += v;
        l += l&-l;
    }
}

int get_s(int l1, int l2) {
    return get(l2) - get(l1-1);
}

int calc_lim(int prev, int curr) {
    if (arr[curr] <= arr[prev]) return INF;

    int tot = get_s(prev, curr);
    int th = arr[curr] * (curr-prev+1);

    int diff = tot - th;
    
    int for_each = (arr[curr] - arr[prev]);

    return max(0, (diff + for_each-1) / for_each) + (curr-prev+1);
}

int calc(int pos, int dest, int h) {
    int diag = get_s(pos, dest);
    int rem = h - (dest-pos+1);

    return diag + rem * arr[pos];
}

int n,m,a,b;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        upd(i, arr[i]);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b); 
        query[i] = make_pair(b, make_pair(a, i));
    }

    sort(query, query+m);
    int next_query = 0;

    for (int i = 1; i <= n; i++) {
        while (bs >= 1 && arr[best[bs-1]] >= arr[i]) bs--;

        while (bs >= 2 &&
               calc_lim(best[bs-1], i) >= calc_lim(best[bs-2], best[bs-1]) + i-best[bs-1]) {
            //printf("Removing %d because %d >= %d\n", best[bs-1], calc_lim(best[bs-1], i), calc_lim(best[bs-2], best[bs-1]));
            bs--;
        }

        best[bs++]=i;

        /*printf("After modification %d: \n", i);
        for (int j = 0; j < bs; j++) {
            printf("%d ", best[j]);
        }
        printf("\n");*/
    
        while (next_query < m && query[next_query].first == i) {
            int h = query[next_query].second.first;
            
            int st = 0, end = bs-1;
            while (st < end) {
                int mid = (st+end)/2;
                //printf("st = %d end = %d Lim for %d is %d\n", st, end, mid, calc_lim(best[mid], best[mid+1]) + i-best[mid+1]);
                if (calc_lim(best[mid], best[mid+1]) + (i-best[mid+1]) <= h) end = mid;   
                else st = mid+1;
            }

            //printf("query (%d %d) comes from %d (%d)\n", query[next_query].first, query[next_query].second.first, best[st], bs);

            ans[query[next_query].second.second] = calc(best[st], i, h);
            next_query++;
        }
    }

    for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
}