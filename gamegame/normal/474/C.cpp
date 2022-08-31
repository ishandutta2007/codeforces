#include<bits/stdc++.h>
using namespace std;
int a[4],b[4],x[4],y[4];
void rotate(int& xx,int& yy,int aa,int bb){
	xx-=aa;
	yy-=bb;
	swap(xx,yy);
	xx=-xx;
	xx+=aa;
	yy+=bb;
}
int zx[4],zy[4];
bool check(){
	int sx=0,sy=0;
	for(int i=0; i<4 ;i++){
		zx[i]=x[i]*4;
		zy[i]=y[i]*4;
		sx+=zx[i];
		sy+=zy[i];
	}
	sx/=4;sy/=4;
	for(int i=0; i<4 ;i++){
		zx[i]-=sx;zy[i]-=sy;
	}
	if(zx[0]==0 && zy[0]==0) return false;
	for(int j=1; j<=3 ;j++){
		rotate(zx[0],zy[0],0,0);
		bool ok=false;
		for(int i=1; i<4 ;i++){
			if(zx[0]==zx[i] && zy[0]==zy[i]) ok=true;
		}
		if(!ok) return false;
	}
	return true;
}
void solve(){
	for(int i=0; i<4 ;i++){
		cin >> x[i] >> y[i] >> a[i] >> b[i];
	}
	int ans=13;
	for(int i=0; i<4 ;i++,rotate(x[0],y[0],a[0],b[0])){
		for(int j=0; j<4 ;j++,rotate(x[1],y[1],a[1],b[1])){
		for(int k=0; k<4 ;k++,rotate(x[2],y[2],a[2],b[2])){
		for(int l=0; l<4 ;l++,rotate(x[3],y[3],a[3],b[3])){
		if(check()) ans=min(ans,i+j+k+l);
	}
	}
	}
	}
	if(ans==13) cout << "-1\n";
	else cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--) solve();
}