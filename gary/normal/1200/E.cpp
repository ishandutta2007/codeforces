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
#define KEEP while(1)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n;
string pre,res="",proce;
int z[2000000+10];
int main(){
//	FREO;
	cin>>n;
	rb(iT,1,n){
		cin>>pre;
		if(iT==1){
			res+=pre;
			continue;
		}
		proce=" ";
		proce+=pre;
		int tmplen=min(res.length(),pre.length());
		rb(i,res.length()-tmplen,res.length()-1) proce+=res[i];
//		memset(z,0,sizeof(z));
		int len=proce.length();
		int r_bound=1,l_bound=2;
		z[2]=0;
		rb(i,2,len){
			if(proce[i]!=proce[i-1]) break;
			else{
			z[2]++;
			r_bound=i;
			} 
		}
		len--;
//		cout<<endl;
		rb(i,3,len){
			z[i]=0;
			if(i<=r_bound){
				z[i]=z[i-l_bound+1];
				z[i]=min(z[i],r_bound-i+1);
				if(z[i]+i-1==r_bound){
					int ite=z[i]+1;
					rb(j,i+z[i],len){
						if(proce[j]!=proce[ite++]) break;
						else {
							z[i]++;
						}
//						cout<<j<<" ";
					}
					l_bound=i;
					r_bound=i+z[i]-1;
				}
			}
			else{
				int ite=1;
				rb(j,i,len){
					if(proce[j]!=proce[ite++]) break;
					else {
						z[i]++;
					}
//					cout<<j<<" ";
				}
				l_bound=i;
				r_bound=i+z[i]-1;
			}
		} 
//		cout<<proce<<":";
//		 rb(i,2,len){
//		 	cout<<z[i]<<",";
//		 }
//		 cout<<endl;
		int len2=pre.length();
		int end_line=0;
		rb(i,1,len){
			if(z[i]+i-1==len&&z[i]<=min(len2,int(res.length()))){
				end_line=z[i];
				break;
			}
		}
		rb(i,end_line,len2-1){
			res+=pre[i];
		}
	}
	cout<<res<<endl;
	return 0;
}
/*
2
Gc cGc
*/