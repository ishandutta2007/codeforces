#include<bits/stdc++.h>
using namespace std;
#define forinc(i,a,b) for(int i=a;i<=b;++i)
const int N=300010;
int n,kq,h,a[N];
bool cheq(int i)
{
    int H=0;
    sort(a+1,a+i+1);
    for(;i>0;i-=2) H+=a[i];
    return H<=h;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>h;
    forinc(i,1,n) cin>>a[i];
    kq=1;
    while(kq<=n&&cheq(kq)) ++kq;
    cout<<kq-1;
}