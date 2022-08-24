#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
int n,q,bs,bc;
int a[200001];
int bit[600][200001];
void add(int b,int id,int v){
	for(int i=id; i<=n ;i+=i&-i){
		bit[b][i]+=v;
	}
}
int query(int b,int id){
	int ans=0;
	for(int i=id; i>=1 ;i-=i&-i){
		ans+=bit[b][i];
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> q;
	int bs=400;
	int bc=(n-1)/bs+1;
	long long ans=0;
	for(int i=1; i<=n ;i++){
		a[i]=i;
		add((i-1)/bs,i,1);
	}
	for(int i=1; i<=q ;i++){
		int l,r;
		cin >> l >> r;
		if(l==r){
			cout << ans << '\n';
			continue;
		}
		if(l>r) swap(l,r);
		int bl=(l-1)/bs;
		int br=(r-1)/bs;
		int al=a[l];
		int ar=a[r];
		if(al>ar) swap(al,ar);
		long long cnt=0;
		if(bl==br){
			for(int j=l+1; j<r ;j++){
				if(a[j]>al && a[j]<ar) cnt++;
			}
		}
		else{
			for(int j=l+1; j<=min(n,(bl+1)*bs) ;j++){
				if(a[j]>al && a[j]<ar) cnt++;
			}
			for(int j=br*bs+1; j<r ;j++){
				if(a[j]>al && a[j]<ar) cnt++;
			}
			for(int j=bl+1; j<br ;j++){
				cnt+=query(j,ar)-query(j,al-1);
			}
			add(bl,a[l],-1);
			add(bl,a[r],1);
			add(br,a[l],1);
			add(br,a[r],-1);			
		}
		cnt=cnt*2+1;
		if(a[l]>a[r]) ans-=cnt;
		else ans+=cnt;
		cout << ans << '\n';
		swap(a[l],a[r]);
	}
}