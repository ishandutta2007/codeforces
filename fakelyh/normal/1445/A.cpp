#include<bits/stdc++.h>
using namespace std;
int main(){
    register int t,n,x,a[55],b[55];
	cin>>t;
	while(t--){
        cin>>n>>x;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        bool flag=0;
        stable_sort(a+1,a+1+n);
        stable_sort(b+1,b+1+n,greater<int>());
        for(int i=1;i<=n;i++)if(a[i]+b[i]>x){flag=1;break;}
        puts(flag?"No":"Yes");
    }
}