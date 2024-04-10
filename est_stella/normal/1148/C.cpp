#include<bits/stdc++.h>
using namespace std;

int n;
int a[300001];
int lo[300001];
vector< pair<int,int> > ans;

int main()
{
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
        scanf("%d", &a[i]), lo[a[i]] = i;

    for(int i=1; i<=n; i++) {
        int j = lo[i];

        if(i == j) continue;

        if(i > n/2) {
            swap(a[j], a[1]);
            swap(lo[a[j]], lo[a[1]]);
            swap(a[1], a[i]);
            swap(lo[a[i]], lo[a[1]]);
            swap(a[j], a[1]);
            swap(lo[a[j]], lo[a[1]]);

            ans.push_back({1, j});
            ans.push_back({1, i});
            ans.push_back({1, j});
        }
        else if(j <= n/2) {
            swap(a[j], a[n]);
            swap(lo[a[j]], lo[a[n]]);
            swap(a[n], a[i]);
            swap(lo[a[i]], lo[a[n]]);

            ans.push_back({j, n});
            ans.push_back({i, n});
        }
        else if( j > n/2 && i <= n/2 ) {
            if(i==1) {
                swap(a[1], a[j]);
                swap(lo[a[1]], lo[a[j]]);

                ans.push_back({1, j});
            }
            else {
                swap(a[j], a[1]);
                swap(lo[a[j]], lo[a[1]]);
                swap(a[1], a[n]);
                swap(lo[a[n]], lo[a[1]]);
                swap(a[i], a[n]);
                swap(lo[a[n]], lo[a[i]]);

                ans.push_back({1, j});
                ans.push_back({1, n});
                ans.push_back({i, n});

                if(j != n) {
                    swap(a[j], a[1]);
                    swap(lo[a[j]], lo[a[1]]);
                    ans.push_back({j, 1});
                }
            }
        }
    }

    printf("%d\n", ans.size());
    for(int i=0; i<ans.size(); i++) {
        if(ans[i].first > ans[i].second) swap(ans[i].first, ans[i].second);
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
}