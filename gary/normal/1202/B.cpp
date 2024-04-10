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
#define FREO freopen("check.out","r",stdin)
#define rep(a,b) for(int a=0;a<b;++a)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int v[10];
int near[10][10][10][10];
int main(){
//	FREO;
	rb(from,0,9)
		rb(to,0,9){
			rb(i,0,9){
				rb(j,0,9){
					memset(v,0,sizeof(v));
					queue<int> q;
					queue<int> cost;
					cost.push(1);
					cost.push(1);
					q.push((from+i)%10);
					q.push((from+j)%10);
					near[from][to][i][j]=-1;
//					if(from==to) near[from][to][i][j]=0;
//					else
					while(!q.empty()){
					int N=q.front();
					int C=cost.front();
					q.pop();
					cost.pop();
					if(v[N]){
						continue;
					} 
					v[N]=1;
					if(N==to){
						near[from][to][i][j]=C-1;
						break;
					}
					q.push((N+i)%10);
					q.push((N+j)%10);
					cost.push(C+1);
					cost.push(C+1);
					}
				}
			}
		}
	string s;
	cin>>s;
	int len=s.length();
	rb(i,0,9)
	{
		rb(j,0,9){
			LL res=0;
			rb(k,1,len-1){
				int las=s[k-1]-'0';
				int now=s[k]-'0';
				int to=near[las][now][i][j];
				res+=to;
				if(to==-1){
					res=-1;
					break;
				}
			}
			printf("%I64d ",res);
		}
		cout<<endl;
	}
	return 0;
}