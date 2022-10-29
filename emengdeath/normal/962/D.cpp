#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,sum;
long long a[N];
map<long long,int>f;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    sum=n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        while (f[a[i]]){
            int x=f[a[i]];
            f[a[i]]=0;
            a[x]=0;
            a[i]<<=1;
            sum--;
        }
        f[a[i]]=i;
    }
    cout<<sum<<endl;
    for (int i=1;i<=n;i++)
        if (a[i])
            cout<<a[i]<<' ';
    return 0;
}