#include<iostream>
using namespace std;
int n;
int sa[18][200001];
int sb[18][200001];
int log[200001];
int maxa(int left,int right){
	int loog=log[right-left+1];
	right-=(1<<loog)-1;
	return max(sa[loog][left],sa[loog][right]);
}
int minb(int left,int right){
	int loog=log[right-left+1];
	right-=(1<<loog)-1;
	return min(sb[loog][left],sb[loog][right]);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	log[0]=-1;
	for(int i=1; i<=n ;i++){
		log[i]=log[i/2]+1;
		cin >> sa[0][i];
	}
	for(int i=1; i<=n ;i++){
		cin >> sb[0][i];
	}
	for(int i=1; i<=log[n] ;i++){
		for(int j=1; j<=(n-(1<<i)+1) ;j++){
			sa[i][j]=max(sa[i-1][j],sa[i-1][j+(1<<(i-1))]);
			sb[i][j]=min(sb[i-1][j],sb[i-1][j+(1<<(i-1))]);
		}
	}
	int l,r,s,b,mid;
	long long ans=0;
	for(int i=1; i<=n ;i++){
		if(maxa(i,n)<minb(i,n) || sa[0][i]>sb[0][i]) continue;
		l=i-1,r=n;
		while(l!=r){
			mid=(l+r+1)/2;
			if(maxa(i,mid)>=minb(i,mid)) r=mid-1;
			else l=mid;
		}
		s=l;
		l=i,r=n+1;
		while(l!=r){
			mid=(l+r)/2;
			if(maxa(i,mid)<=minb(i,mid)) l=mid+1;
			else r=mid;
		}
		b=r;
		ans+=b-s-1;
	}
	cout << ans << endl;
}