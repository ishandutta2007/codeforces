/*
AuThOr GaRyMr
*/
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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,m,f[5005],h[5005],l[5005],r[5005];
vector<mp> s[5005];
const int MOD=1e9+7;
int grass[5005];
inline int Read()
{
    int x=0,f=1;char c=getchar();
    while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
    return x*f;
}
int main(){
	fastio;
	n=Read();
	m=Read();
	rb(i,1,n)
		grass[i]=Read();
	rb(i,1,m)
	f[i]=Read(),h[i]=Read();
	rb(i,1,m){
		int cnt=0;
		l[i]=r[i]=-1;
		rb(j,1,n)
		{
			if(f[i]==grass[j]){
				cnt++;
			}
			if(cnt==h[i]){
				l[i]=j;
				break;
			}
		}
		cnt=0;
		rl(j,n,1){
			if(f[i]==grass[j])
				cnt++;
			if(cnt==h[i]){
				r[i]=j;
				break;
			}
		}
	}
	rb(i,1,m)
		if(l[i]>0)
		s[f[i]].PB(II(l[i],r[i]));
	pair<int,LL> res={0,1};
	rb(i,1,m){
		if(l[i]==-1) continue;
		//choose i-th cow as the left first 
		pair<int,LL> tmp={1,1};
		int bound=l[i];
		//all left cows can't beyond "bound",the cows in the right as well
		rb(j,1,5000){
			//iterate the SET
			if(s[j].empty()) continue;
			int sat_l[5005];
			int sl,sr;
			sl=sr=0;
			for(auto it:s[j]){
				if(it.FIR<bound)sat_l[++sl]=it.SEC;//satisfy
				if(it.SEC>bound) sr++;
			}
			if(f[i]==j){
				if(sr-bool(r[i]>l[i])){
					tmp.FIR++;
					tmp.SEC*=sr-bool(r[i]>l[i]);
					tmp.SEC%=MOD;
				}
			}
			else{
				if(!sl&&!sr) continue;
				if(!sr){
					tmp.FIR++;
					tmp.SEC*=sl;
					tmp.SEC%=MOD;
				}
				else
				if(!sl){
					tmp.FIR++;
					tmp.SEC*=sr;
					tmp.SEC%=MOD;
				}
				else{
					if(sl==1&&sr==1){
						if(sat_l[1]>bound)
						{
							tmp.FIR++;
							tmp.SEC<<=1;
							tmp.SEC%=MOD;
						}
						else{
							tmp.FIR+=2;
						}
					}
					else{
						tmp.FIR+=2;
						LL cont=0;
						rb(K,1,sl){
							int it=sat_l[K];
							if(it>bound){
								cont+=sr-1;
							}
							else{
								cont+=sr;
							}
							cont%=MOD;
						}
						tmp.SEC*=cont;
						tmp.SEC%=MOD;
					}
				}
			}
		}
		if(tmp.FIR>res.FIR){
			res=tmp;
		}
		else if(tmp.FIR==res.FIR)
			res.SEC+=tmp.SEC,res.SEC%=MOD;
	}
	//
	pair<int,LL> tmp;
	tmp={0,1};
	rb(i,1,5000)
		if(s[i].size()){
			tmp.FIR++;
			tmp.SEC*=s[i].size();
			tmp.SEC%=MOD;
		} 
	if(tmp.FIR>res.FIR){
		res=tmp;
	}
	else if(tmp.FIR==res.FIR)
		res.SEC+=tmp.SEC;
	if(res.FIR==0){
		res.SEC=1;
	}
	res.SEC%=MOD;
	cout<<res.FIR<<" "<<res.SEC;
	return 0;
}
/*
7 8
2 3 4 5 4 3 2
2 1
2 1
3 1
3 1
4 1
4 1
5 1
5 1
*/