//LUO GU BOTE
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
const int MAXN=2000;
char c[MAXN+10][MAXN+10];
map<char,int> app;
map<char,int> have;
map<char,superpair> appear; 
map<char,int> represent;
void WASH(){
	app.clear();
	have.clear();
	appear.clear();
	represent.clear();
}
bool NO_ANS=0;
bool OK=0;
void _do(char now){
	mp st,ed;
	st=appear[now].FIR;
	ed=appear[now].SEC;
	if(st.FIR==ed.FIR){//A SNAKE THAT LIE
		rb(i,st.SEC,ed.SEC){
			if(c[st.FIR][i]!='.'&&c[st.FIR][i]<now) NO_ANS=1;
			if(c[st.FIR][i]=='.') NO_ANS=1;
		}
	} 
	else{//A SNAKE STAND
		rb(i,st.FIR,ed.FIR){
			if(c[i][st.SEC]!='.'&&c[i][st.SEC]<now) NO_ANS=1;
			if(c[i][st.SEC]=='.') NO_ANS=1;
		}
	}
}
void solve(){
    NO_ANS=0;
    OK=0;
	WASH();
	char max_app_char='a'-1;
	int n,m;
	scanf("%d %d",&n,&m);
	rb(i,1,n)
		rb(j,1,m){
		cin>>c[i][j];
		if(c[i][j]!='.') have[c[i][j]]=1;
		if(c[i][j]!='.')app[c[i][j]]=1;
		if(c[i][j]!='.')max_app_char=max(max_app_char,c[i][j]);
		} 
	rb(i,1,26){
		char tmp_char='a'+i-1;
		if(tmp_char<=max_app_char){
			have[tmp_char]=1;
		}
	}
	map<int,int> tmp_app;
	rb(i,1,n){
		rb(j,1,m){
			if(c[i][j]=='.') continue; 
			if(!tmp_app[c[i][j]]){
				tmp_app[c[i][j]]=1;
				appear[c[i][j]].FIR=II(i,j);
//				cout<<"F"<<c[i][j]<<"-"<<i<<"-"<<j<<endl;
			} 
			if(tmp_app[c[i][j]]){
			    if(i!=appear[c[i][j]].FIR.FIR&&j!=appear[c[i][j]].FIR.SEC){
			        printf("NO\n");
			        return;
			    }
				if(represent[c[i][j]]){
				    if((represent[c[i][j]]==1&&i!=appear[c[i][j]].FIR.FIR)||(represent[c[i][j]]==2&&j!=appear[c[i][j]].FIR.SEC)){
				       	printf("NO\n");
					    return; 
				    }
				
				}
				else{
				    if(i!=appear[c[i][j]].FIR.FIR||j!=appear[c[i][j]].FIR.SEC){
				        if(i==appear[c[i][j]].FIR.FIR){
				            represent[c[i][j]]=1;
				        }
				        else{
				            represent[c[i][j]]=2;
				        }
				    }
				}
				appear[c[i][j]].SEC=II(i,j);
//				cout<<"S"<<c[i][j]<<"-"<<i<<"-"<<j<<endl;
			}
		}
	}
//	cout<<"*"<<represent['a']<<endl;
	OK=0;
	superpair _std;
	rb(i,1,26)
	{
		char tmp_char='a'-1+i;
		if(app[tmp_char]){
			_std=appear[tmp_char];
			_do(tmp_char);
		}
	}
	if(NO_ANS){
		printf("NO\n");
	}
	else{
		printf("YES\n");
		printf("%d\n",max_app_char-'a'+1);
		rb(i,1,26){
			char tmp_char='a'+i-1;
			
			if(have[tmp_char]){
				if(app[tmp_char]){//cout<<tmp_char<<endl;
					printf("%d %d %d %d\n",appear[tmp_char].FIR.FIR,appear[tmp_char].FIR.SEC,appear[tmp_char].SEC.FIR,appear[tmp_char].SEC.SEC);
				}
				else{
					appear[tmp_char]=_std;
					printf("%d %d %d %d\n",appear[tmp_char].FIR.FIR,appear[tmp_char].FIR.SEC,appear[tmp_char].SEC.FIR,appear[tmp_char].SEC.SEC);
				}
			}
			else break;
		}
	}
} 
int main(){
//	freopen("Snakes.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	} 
	return 0;
}