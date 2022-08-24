#include<bits/stdc++.h>
using namespace std;
const int arin=43;
const int jiho=4;
const int yerin=64;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
int f[8888];
int ran(int x){
	//return rand()%x;
	return uniform_int_distribution<int>(0,x-1)(rng);
}
int ask(int x,int y){
	cout << "? " << x << ' ' << y << endl;
	int z;cin >> z;
	return z;
}
int ans[1011][1011];
int qx[8888],qy[8888],qz[8888];
void easy(){
	for(int i=1; i<=n ;i++){
		for(int j=i+1; j<=n ;j++){
			ans[i][j]=ans[j][i]=ask(i,j);
		}
	}
	for(int i=1; i<=n ;i++){
		f[i]=2047;
		for(int j=1; j<=n ;j++) if(j!=i) f[i]&=ans[i][j];
	}
	cout << "! ";
	for(int i=1; i<=n ;i++) cout << f[i] << ' ';
	cout << endl;
}
int p[201];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	if(n<=yerin){
		easy();
		return 0;
	}
	for(int i=1; i<=arin ;i++){
		qx[i]=ran(n)+1;
		qz[i]=2047;
		for(int j=1; j<=jiho ;j++){
			int y=ran(n-1)+1;
			if(y>=qx[i]) y++;
			qz[i]&=ask(qx[i],y);
		}
	}
	for(int i=1; i<=arin ;i++){
		for(int j=i+1; j<=arin ;j++){
			if((qz[i]&qz[j])==0){
				int bona=qx[i],luda=qx[j];
				int wjsn=ask(bona,luda);
				f[bona]=f[luda]=wjsn;
				for(int k=1; k<=n ;k++){
					if(k==bona || k==luda) continue;
					int p1=ask(bona,k);
					int p2=ask(luda,k);
					f[k]=p1&p2;
					f[bona]&=p1;
					f[luda]&=p2;
				}
				cout << "! ";
				for(int k=1; k<=n ;k++) cout << f[k] << ' ';
				cout << endl;
				return 0;
			}
		}
	}
	cout << "haha anton trygub orz" << endl;
}