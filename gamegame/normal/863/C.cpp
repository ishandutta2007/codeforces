#include<iostream>
using namespace std;
typedef long long ll;
int a[4][4],b[4][4],t[4][4];
int x,y;
ll k,aw,bw;
int win(int i,int j){
	return ((i-j+3)%3==1);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> k >> x >> y;
	for(int i=1; i<=3 ;i++){
		for(int j=1; j<=3 ;j++){
			cin >> a[i][j];
		}
	}
	for(int i=1; i<=3 ;i++){
		for(int j=1; j<=3 ;j++){
			cin >> b[i][j];
		}
	}
	t[x][y]=1;
	int p=a[x][y],q=b[x][y],r;
	int cnt=1;
	while(t[p][q]==0){
		cnt++;
		t[p][q]=cnt;
		r=a[p][q];
		q=b[p][q];
		p=r;
	}
	cnt-=t[p][q]-1;
	if(k<t[p][q]){
		for(int i=1; i<=3 ;i++){
			for(int j=1; j<=3 ;j++){
				if(t[i][j]<=k && t[i][j]!=0){
					aw+=win(i,j);
					bw+=win(j,i);
				}
			}
		}
		cout << aw << ' ' << bw << endl;
		return 0;
	}
	for(int i=1; i<=3 ;i++){
		for(int j=1; j<=3 ;j++){
			if(t[i][j]<t[p][q] && t[i][j]!=0){
				aw+=win(i,j);
				bw+=win(j,i);
			}
		}
	}
	k-=t[p][q]-1;
	int cycaw=0,cycbw=0;
	for(int i=1; i<=3 ;i++){
		for(int j=1; j<=3 ;j++){
			if(t[i][j]>=t[p][q]){
				cycaw+=win(i,j);
				cycbw+=win(j,i);
			}
		}
	}
	aw+=k/cnt*cycaw;
	bw+=k/cnt*cycbw;
	for(int i=1; i<=3 ;i++){
		for(int j=1; j<=3 ;j++){
			if(t[i][j]<t[p][q]+k%cnt && t[i][j]>=t[p][q]){
				aw+=win(i,j);
				bw+=win(j,i);
			}
		}
	}
	cout << aw << ' ' << bw << endl;
}