#include<bits/stdc++.h>
using namespace std;
const int N=2e6+1;
int a[N],d[N],b[N];
bool bz[N];
int n;
void change(int x){
    int y=x;
    while (x<N)bz[x]=1,x+=y;
}
void did(int x){
    for (int j=1;(long long)j*j<=x;j++)
        if (x%j==0){
            if (d[a[j]]==j&&!bz[j])change(j);
            if (d[a[x/j]]==x/j&&!bz[x/j])change(x/j);
        }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i=2;i<N;i++){
        if (!a[i])
            d[a[i]=++d[0]]=i;
        for (int j=1;j<=a[i];j++)
            if ((long long)d[j]*i>=N)break;
            else
                a[d[j]*i]=j;
    }
    bool sig=0;
    int l=2;
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        if (!sig){
            for (int j=1;(long long)j*j<=x;j++)
                if (x%j==0){
                    if (d[a[j]]==j&&bz[j]){
                        sig=1;
                        break;
                    }
                    if (d[a[x/j]]==x/j&&bz[x/j]){
                        sig=1;
                        break;
                    }
                }
            if (!sig){
                did(x);
                cout<<x<<' ';
            }else{
                int r=l;
                while (bz[r]||r<x)r++;
                cout<<r<<' ';
                did(r);
            }
        }else{
            while (bz[l])++l;
            cout<<l<<' ';
            did(l);
        }
    }
    return 0;
}