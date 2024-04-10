/*
{

AuThOr Gwj
*/
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int f[9][9][9][2];
pair<pair<mp,mp>,pair<mp,int> > las[9][9][9][2]; 
string s[3],S;
int main(){
	fastio;
	R(S);
	int now=0;
	rep(i,3)
		s[i]="";
	int old[3]={0};
	rep(i,S.length()){
		if(S[i]<='9'&&S[i]>='0'){
			s[now]+=S[i];
			old[now]++;
		}
		else{
			now++;
		}
	}
	rep(i,3)
		reverse(ALL(s[i]));
	rep(i,10)
		rep(j,3)
			s[j]+='&'; 
	rep(i,3)
		s[i]='^'+s[i];
	memset(f,63,sizeof(f));
	f[0][0][0][0]=0;
	rep(i,9)
	{
		rep(j,9){
			rep(k,9){
				rep(l,2){
					if(f[i][j][k][l]!=INF){
						rep(I,10){
							if(I&&i==old[0]&&las[i][j][k][l].SEC.FIR.FIR==0) continue;
							
							rep(J,10){
								int K=(I+J+l)%10;
								if(J&&j==old[1]&&las[i][j][k][l].SEC.FIR.SEC==0) continue;
								if(K&&k==old[2]&&las[i][j][k][l].SEC.SEC==0) continue;
								int ni,nj,nk;
								int cost=0;
								if(I==s[0][i+1]-'0'){
									ni=i+1;
								}
								else{
									ni=i;
									if(I||i!=old[0])
									cost++;
								}
								if(J==s[1][j+1]-'0'){
									nj=j+1;
								}
								else{
									nj=j;
									if(J||j!=old[1])
									cost++;
								}
								if(K==s[2][k+1]-'0'){
									nk=k+1;
								}
								else{
									nk=k;
									if(K||k!=old[2])
									cost++;
								}
//								if(i==5&&j==5&&k==6&&l==1&&I==1&&J==7&&K==8){
//									cout<<ni<<" "<<nj<<" "<<nk<<" "<<cost<<endl;
//								}
//								cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<I<<" "<<J<<" "<<K<<" "<<" "<<ni<<" "<<nj<<" "<<nk<<cost<<endl;
								if(f[i][j][k][l]+cost<f[ni][nj][nk][I+J+l>=10]){
									f[ni][nj][nk][I+J+l>=10]=f[i][j][k][l]+cost;
									las[ni][nj][nk][I+J+l>=10]=II(II(II(i,j),II(k,l)),II(II(I,J),K));	
								}
							}
						}
					}
				}
			}
		}
	}
	int i,j,k,l=0;
	i=old[0];
	j=old[1];
	k=old[2];
	string res[3];
//		cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<f[i][j][k][l]<<endl; 
	while(i!=0||j!=0||k!=0||l!=0){
		res[0]+='0'+las[i][j][k][l].SEC.FIR.FIR;
		res[1]+='0'+las[i][j][k][l].SEC.FIR.SEC;
		res[2]+='0'+las[i][j][k][l].SEC.SEC;
		int ni,nj,nk,nl;
		ni=las[i][j][k][l].FIR.FIR.FIR;
		nj=las[i][j][k][l].FIR.FIR.SEC;
		nk=las[i][j][k][l].FIR.SEC.FIR;
		nl=las[i][j][k][l].FIR.SEC.SEC;
		i=ni;
		j=nj;
		k=nk;
		l=nl;
//		cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<f[i][j][k][l]<<endl; 
	}
	rep(i,3){
		bool ok=1;
		rep(j,res[i].length()){
			if(ok&&res[i][j]=='0'){
				continue;
			}
			ok=0;
			cout<<res[i][j];
		}
		if(i==0){
			cout<<"+";
		}
		if(i==1){
			cout<<"=";
		}
	}
	return 0;
}