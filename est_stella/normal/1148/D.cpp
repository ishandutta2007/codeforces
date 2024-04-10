#include<bits/stdc++.h>
using namespace std;

int n;
vector< pair<int,int> > v1;
vector< pair<int,int> > v2;

int main()
{
    scanf("%d", &n);

    for(int i=1; i<=n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(a < b) v1.push_back({b, i});
        else v2.push_back({a, i});
    }

    if(v1.size() > v2.size()) {
        printf("%d\n", v1.size());
        sort(v1.begin(), v1.end());

        for(int i=v1.size()-1; i>=0; i--) {
            printf("%d ", v1[i].second);
        }
    }
    else {
        printf("%d\n", v2.size());
        sort(v2.begin(), v2.end());

        for(int i=0; i<v2.size(); i++) {
            printf("%d ", v2[i].second);
        }
    }
}