//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;

int RES=INF;
char tab[4]={'A','G','C','T'};
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<char> > input(n+1);
	rb(i,1,n){
		input[i].PB('$');
		rb(j,1,m){
			char tmp;
			cin>>tmp;
			input[i].PB(tmp);
		}
	}
	vector<vector<char> > res(n+1);
	vector<vector<char> > TMPRES(n+1);
	rb(i,1,n)
		rb(j,1,m+1) TMPRES[i].PB('$'),res[i].PB('$'); 
	rep(A,4){
		rb(B,A+1,3){
			rb(C,0,3){
				if(C!=A&&C!=B){
					rb(D,C+1,3){
						if(D!=A&&D!=B){
							int isres=0;
							char now1,now2,res1,res2;
							now1=tab[A];
							now2=tab[B];
							res1=tab[C];
							res2=tab[D];
//							cout<<now1<<" "<<now2<<" "<<res1<<" "<<res2<<endl;
							rb(i,1,n){
								//now1 first,now2 firsr
								int tmpres1,tmpres2;
								tmpres1=tmpres2=0;
								int ISNOW=0;
								rb(j,1,m){
									if(ISNOW==1){
										if(input[i][j]!=now2) tmpres1++;
									}
									else{
										if(input[i][j]!=now1) tmpres1++;
									}
									ISNOW^=1;
								}
								ISNOW=1;
								rb(j,1,m){
									if(ISNOW==1){
										if(input[i][j]!=now2) tmpres2++;
									}
									else{
										if(input[i][j]!=now1) tmpres2++;
									}
									ISNOW^=1;
								}
								if(tmpres1<tmpres2){
									isres+=tmpres1;
									ISNOW=0;
									rb(j,1,m){
									if(ISNOW==1){
										TMPRES[i][j]=now2;
									}
									else{
										TMPRES[i][j]=now1;
									}
									ISNOW^=1;
									}
								}
								else{
									isres+=tmpres2;
									ISNOW=1;
									rb(j,1,m){
									if(ISNOW==1){
										TMPRES[i][j]=now2;
									}
									else{
										TMPRES[i][j]=now1;
									}
									ISNOW^=1;
									}
									
								}
								swap(now1,res1);
								swap(now2,res2); 
							}
							if(isres<RES){
								res=TMPRES;
								RES=isres;
							}
							
						}
					}
				}
			}
		}
	}
	rep(A,4){
		rb(B,A+1,3){
			rb(C,0,3){
				if(C!=A&&C!=B){
					rb(D,C+1,3){
						if(D!=A&&D!=B){
							int isres=0;
							char now1,now2,res1,res2;
							now1=tab[A];
							now2=tab[B];
							res1=tab[C];
							res2=tab[D];
//							cout<<now1<<" "<<now2<<" "<<res1<<" "<<res2<<endl;
							rb(j,1,m){
								//now1 first,now2 firsr
								int tmpres1,tmpres2;
								tmpres1=tmpres2=0;
								int ISNOW=0;
								rb(i,1,n){
									if(ISNOW==1){
										if(input[i][j]!=now2) tmpres1++;
									}
									else{
										if(input[i][j]!=now1) tmpres1++;
									}
									ISNOW^=1;
								}
								ISNOW=1;
								rb(i,1,n){
									if(ISNOW==1){
										if(input[i][j]!=now2) tmpres2++;
									}
									else{
										if(input[i][j]!=now1) tmpres2++;
									}
									ISNOW^=1;
								}
								if(tmpres1<tmpres2){
									isres+=tmpres1;
									ISNOW=0;
									rb(i,1,n){
									if(ISNOW==1){
										TMPRES[i][j]=now2;
									}
									else{
										TMPRES[i][j]=now1;
									}
									ISNOW^=1;
									}
								}
								else{
									isres+=tmpres2;
									ISNOW=1;
									rb(i,1,n){
									if(ISNOW==1){
										TMPRES[i][j]=now2;
									}
									else{
										TMPRES[i][j]=now1;
									}
									ISNOW^=1;
									}
									
								}
								swap(now1,res1);
								swap(now2,res2); 
							}
							if(isres<RES){
								res=TMPRES;
								RES=isres;
							}
							
						}
					}
				}
			}
		}
	}
//	cout<<"FININSH"<<endl;
	rb(i,1,n)
	{
		rb(j,1,m){
			
			cout<<res[i][j];
		}
		cout<<endl;
	}
	return 0;
}