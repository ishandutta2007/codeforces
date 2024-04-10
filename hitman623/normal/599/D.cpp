#include <bits/stdc++.h>
#define pb push_back
using namespace std;
long long a[1000005][2],k=0,p,i,f=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long double x;
    cin>>x;
    p=ceil(pow(x,0.333333333));
    for(i=1;i<=2*p+2;++i)
    {
        if((long long)(6*x+i*i*i-i)%(3*i*(i+1))) continue;
        if((6*x+i*i*i-i)/(3*i*(i+1))<i) break;
        if((6*x+i*i*i-i)/(3*i*(i+1))==i) {f=i;break;}
        a[k][0]=i;
        a[k][1]=(6*x+i*i*i-i)/(3*i*(i+1));
        k++;
    }
    cout<<2*k+!!f<<endl;
    for(i=0;i<k;++i)
    cout<<a[i][0]<<" "<<a[i][1]<<endl;
    if(f!=0)
    cout<<f<<" "<<f<<endl;
    for(i=k-1;i>=0;--i)
    cout<<a[i][1]<<" "<<a[i][0]<<endl;
    return 0;
}