#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[100005];
bool c[100005],b[100005];
inline int work(int n){
	for(int i=1;i<=n;i++)c[i]=a[i];
	int l=1,r=1,ans=0;
	while(l<=n&&c[l]!=0)l++;
	while(r<=n&&c[r]!=1)r++;
	for(int i=1;i<=n;i++){
		if(!b[i]){
			ans+=l-i;
			swap(c[i],c[l++]);
			while(l<=n&&c[l]!=0)l++;
			while(r<=n&&c[r]!=1)r++;
		}else{
			ans+=r-i;
			swap(c[i],c[r++]);
			while(l<=n&&c[l]!=0)l++;
			while(r<=n&&c[r]!=1)r++;
		}
	}
	return ans;
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        int even=0,odd=0;
        for(register int i=1;i<=n;i++)cin>>a[i],a[i]&=1,even+=!a[i],odd+=a[i];
        if(abs(even-odd)>1){cout<<"-1\n";continue;}
        if(n&1){
			if(odd<even)for(register int i=1;i<=n;i++)b[i]=!(i&1);
			else for(register int i=1;i<=n;i++)b[i]=i&1;
            cout<<work(n)<<endl;
		}else{
			for(register int i=1;i<=n;i++)b[i]=i&1;
			register int tmp=work(n);
			for(register int i=1;i<=n;i++)b[i]^=1;
			cout<<min(tmp,work(n))<<endl;
		}
    }
    return 0;
}