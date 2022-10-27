#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair

int main(){
    int n, m;
    cin>>n;
    m = n/2;
    int p[m];
    for(int i = 0; i < m; i++)cin>>p[i];
    sort(p, p+m);
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < m; i++){
        ans1 += abs(p[i] - 2*i - 1);
        ans2 += abs(p[i] - 2*i - 2);
    }
    cout<<min(ans1, ans2)<<endl;
}