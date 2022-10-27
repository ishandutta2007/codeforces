#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

pair<int,int> a[100005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    int n, h;
    cin>>n>>h;
    for(int i = 0; i < n; i++){
        cin>>a[i].first;
        a[i].second = i;
    }
    if(n == 2){
        cout<<"0\n1 1";
        exit(0);
    }
    sort(a, a+n);
    int tmp1 = a[n-1].first + a[n-2].first - a[1].first - a[0].first;
    int tmp2 = max(a[n-1].first + a[n-2].first, a[n-1].first + a[0].first + h);
    tmp2 -= min(a[2].first + a[1].first, a[1].first + a[0].first + h);
    if(tmp1 > tmp2){
        cout<<tmp2<<endl;
        for(int i = 0; i < n; i++){
            cout<<((a[0].second == i)?1:2)<<" ";
        }
    }else{
        cout<<tmp1<<endl;
        for(int i = 0; i < n; i++){
            cout<<"1 ";
        }
    }
}