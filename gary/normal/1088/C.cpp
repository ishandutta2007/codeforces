#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
const int ma=5e5+10;
int a[N]; 
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
	cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>a[i]; a[i]+=ma;
        }
        cout<<n+1<<endl;
        cout<<1<<' '<<n<<' '<<ma<<endl;
        for(int i=1;i<=n;i++)
        cout<<2<<' '<<i<<' '<<a[i]-i<<endl;
   return 0;
}