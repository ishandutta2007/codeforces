#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,m,ansx[100105],ansy[100105];
pair< pii,int > a[100105];
vector< pii > use_please;
int gen_up;

int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d",&a[i].first.first,&a[i].first.second);
        a[i].first.second = -a[i].first.second;
        a[i].second = i;
    }

    sort(a, a+m);
    int x = 2;
    for (int i = 0; i < m; ++i) {
        if (a[i].first.second) {
            ansx[a[i].second] = 1;
            ansy[a[i].second] = x;
            for (int j = 2; gen_up < m && j < x; ++j) {
                ++gen_up;
                use_please.push_back(make_pair(j, x));
            }
            ++x;
        } else {
            if (!use_please.size()) { cout << -1; return 0; }
            ansx[a[i].second] = use_please.back().first;
            ansy[a[i].second] = use_please.back().second;
            use_please.pop_back();
        }
    }

    for (int i = 0; i < m; ++i)
        printf("%d %d\n", ansx[i], ansy[i]);

    return 0;
}