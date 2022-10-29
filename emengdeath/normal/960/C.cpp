#include<bits/stdc++.h>
using namespace std;
long long x,d;
int a[100];
int n;
int main(){
    ios::sync_with_stdio(false);
    cin>>x>>d;
    long long y;
    for (int i=30;i;i--)
        while (x>=(1<<i)-1){
            a[++a[0]]=i;
            n+=i;
            x-=(1<<i)-1;
        }
    cout<<n<<endl;
    y=1;
    for (int i=1;i<=a[0];i++,y+=d)
        for (int j=1;j<=a[i];j++)
            cout<<y<<' ';
    return 0;
}