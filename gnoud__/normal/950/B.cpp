#include<bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define pii pair<int,int>
#define MAX(a,b,c) max(max(a,b),c)
#define fi first
#define se second
using namespace std;
int a[100001],b[100001];
int main()
{
    int n,m,tong=0,dem=0;
    cin>>n>>m;
    forinc(i,1,n) {cin>>a[i];tong+=a[i];}
    forinc(i,1,m) {cin>>b[i];tong+=b[i];}
    int i=1,tong1=a[1];
    int j=1,tong2=b[1];
    int res=tong1+tong2;
    while(res<tong)
    {
        if(tong1==tong2)
        {
            i++;
            j++;
            tong1+=a[i];
            tong2+=b[j];
            res+=(a[i]+b[j]);
            dem++;
        }
        else if(tong1<tong2)
        {
            i++;
            tong1+=a[i];
            res+=a[i];
        }
        else if(tong1>tong2)
        {
            j++;
            tong2+=b[j];
            res+=b[j];
        }
    }
    cout<<dem+1;
}