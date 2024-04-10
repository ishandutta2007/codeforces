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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
map<mp,int> app;
LL k;int a,b;
LL GO=0;
LL gain_Ali,gain_Bob;
int cos_Ali[4][4],cos_Bob[4][4];
vector<mp> change;
vector<mp> sum;
LL resa,resb;
int main(){
	sum.PB(II(0,0));
	scanf("%I64d %d %d",&k,&a,&b);
	rb(i,1,3){
		rb(j,1,3)
		{
			cin>>cos_Ali[i][j];
		}
	}
	rb(i,1,3){
		rb(j,1,3)
		{
			cin>>cos_Bob[i][j];
		}
	}
	while(1){
		if(app[II(a,b)]){
			resa=sum[app[II(a,b)]-1].FIR;
			resb=sum[app[II(a,b)]-1].SEC;
			k-=app[II(a,b)]-1;
			gain_Ali-=sum[app[II(a,b)]-1].FIR;
			gain_Bob-=sum[app[II(a,b)]-1].SEC;
			int OT=GO;
			GO=0; 
			rb(i,app[II(a,b)],OT){
				GO++;
				change.PB(II(sum[i].FIR-sum[i-1].FIR,sum[i].SEC-sum[i-1].SEC));
			}
			break;
		}
		app[II(a,b)]=GO+1;
		if(a==1){
			if(b==1){
				
			}
			else{
				if(b==2){
					gain_Bob++;
//					change.PB(II(0,1));
				}
				else{
					gain_Ali++;
//					change.PB(II(1,0));
				}
			}
		} 
		else{
			if(a==2){
				if(b==1){
					gain_Ali++;
//					change.PB(II(1,0));
				}
			else{
				if(b==2){
					
				}
				else{
					gain_Bob++;
//					change.PB(II(0,1));
				}
			}
			}
			else{
				if(b==1){
					gain_Bob++;	
//					change.PB(II(0,1));			
				}
			else{
				if(b==2){
					gain_Ali++;
//					change.PB(II(1,0));
				}
				else{
					
				}
			}
			}
		}
		GO++;
		if(GO==k){
			printf("%I64d %I64d\n",gain_Ali,gain_Bob);
			return 0;
		}
//		cout<<a<<" "<<b<<endl;
		sum.PB(II(gain_Ali,gain_Bob));
		int save_a=a;
		a=cos_Ali[a][b];
		b=cos_Bob[save_a][b];
	}
	if(k%GO==0){
		LL has=k/GO;
		printf("%I64d %I64d\n",resa+has*(LL)(gain_Ali),resb+has*(LL)(gain_Bob));
	}
	else{
		LL has=k/GO;
		LL fina=has*(LL)(gain_Ali),finb=has*(LL)(gain_Bob);
		rb(i,1,k%GO){
			fina+=change[i-1].FIR;
			finb+=change[i-1].SEC;
		}
		printf("%I64d %I64d\n",resa+fina,resb+finb);
	}
	return 0;
}