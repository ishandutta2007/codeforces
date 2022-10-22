/**
 *    author:  gary
 *    created: 03.10.2021 09:48:49
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
namespace mypoly{
	const int MOD=998244353;
	const int g=3;
	  int qmul(int x, int y){return 1ll*x*y-1ll*x*y/MOD*MOD;}
	  int qadd(int x, int y){return x+y>=MOD?x+y-MOD:x+y;}
	int G[21][(1<<20)+1],R[21][(1<<20)+1],inver[(1<<20)+1];
	  int quick(int A,int B){
		int res=1;
		while(B){
			if(B&1) res=qmul(res,A);
			A=qmul(A,A);
			B>>=1;
		}
		return res;
	}
	  int inv(int x){
		return quick(x,MOD-2);
	}
	struct POLY{
		int len;
		int rev[1<<20];
		POLY(){
			rb(i,1,(1<<20)) inver[i]=inv(i); 
			rb(i,1,20){
				G[i][0]=1;
				R[i][0]=1;
				int tmp2=inv(quick(g,(MOD-1)>>i)); 
				int tmp=quick(g,(MOD-1)>>i);
				rb(j,1,(1<<i)){
					G[i][j]=qmul(G[i][j-1],tmp);
					R[i][j]=qmul(R[i][j-1],tmp2);
				}
			}
		}
		void butterfly(vector<int> & v){
			rep(i,len){
				rev[i]=rev[i>>1]>>1;
				if(i&1) rev[i]|=len>>1; 
			}
			rep(i,len) if(rev[i]>i) swap(v[i],v[rev[i]]);
		}
		vector<int> ntt(vector<int> v){
			butterfly(v);
			vector<int> nex;
			  int lg=1;
			for(  int l=2;l<=len;l<<=1,++lg){
				nex.clear();
				nex.resize(len);
				for(  int j=0;j<len;j+=l){
					for(  int k=0;k<l/2;++k){
						  int A,B;
						A=v[j+k];
						B=v[j+l/2+k];
						B=qmul(B,G[lg][k]);
						nex[j+k]=qadd(A,B);
						nex[j+k+l/2]=qadd(A,MOD-B);
					}
				}
				v=nex;
			}
			return v;
		}
		vector<int> intt(vector<int> v){
			butterfly(v);
			vector<int> nex;
			  int lg=1;
			for(int l=2;l<=len;l<<=1,++lg){
				nex.clear();
				nex.resize(len);
				for(int j=0;j<len;j+=l){
					for(int k=0;k<l/2;++k){
						  int A,B;
						A=v[j+k];
						B=v[j+l/2+k];
						B=qmul(R[lg][k],B);
						nex[j+k]=qadd(A,B);
						nex[j+k+l/2]=qadd(A,MOD-B);
					}
				}
				v=nex;
			}
			return v;
		}
		void getlen(int x){
			len=1;
			while(len<x){
				len<<=1;
			}
		}
		vector<int> mul(vector<int> A,vector<int> B){
			if(A.size()+B.size()<=25){
				vector<int> ret(A.size()+B.size()-1);
				rep(i,A.size()) rep(j,B.size()) ret[i+j]=qadd(ret[i+j],qmul(A[i],B[j]));
				return ret;
			}
			getlen(A.size()+B.size());
			A.resize(len);
			B.resize(len);
			A=ntt(A);
			B=ntt(B);
			rep(i,len) A[i]=qmul(A[i],B[i]);
			A=intt(A);
			  int iv=inver[len];
			rep(i,len){
				A[i]=qmul(A[i],iv);
			}
			while(!A.empty()&&A.back()==0) A.pop_back();
			return A;
		}
		vector<int> inverse(vector<int> A,int n){
			//% x^n 
			vector<int> ret(n);
			if(n==1){
				ret[0]=quick(A[0],MOD-2);
			}
			else{
				vector<int> oth=inverse(A,(n+1)>>1);
				ret=oth;
				ret.resize(n);
				rep(i,n) ret[i]=(ret[i]+ret[i])%MOD;
				getlen((oth.size()<<1)+A.size());
				oth.resize(len);
				A.resize(len);
				oth=ntt(oth);
				A=ntt(A);
				rep(i,len) oth[i]=qmul(qmul(oth[i],oth[i]),A[i]);
				oth=intt(oth);
				oth.resize(n);
				  int iv=inver[len];
				rep(i,n){
					oth[i]=qmul(oth[i],iv);
				}
				rep(i,n) ret[i]=qadd(ret[i],MOD-oth[i]);
			}
			return ret;
		}
	}poly;
    vector<int> operator * (vector<int> A,vector<int> B){
		return poly.mul(A,B);
	}
	vector<int> operator + (vector<int> A,vector<int> B){
		int Sz=max(A.size(),B.size());
		A.resize(Sz);
		rep(i,B.size()) A[i]=qadd(A[i],B[i]);
		return A;
	}
	vector<int> operator - (vector<int> A,vector<int> B){
		int Sz=max(A.size(),B.size());
		A.resize(Sz);
		rep(i,B.size()) A[i]=qadd(A[i],MOD-B[i]);
		return A;
	}
	vector<int> operator / (vector<int> A,vector<int> B){
		return A*poly.inverse(B,A.size()-B.size()+1);
	}
	vector<int> operator % (vector<int> A,vector<int> B){
		while(A.size()!=1&&A.back()==0) A.POB();
		while(B.size()!=1&&B.back()==0) B.POB();
		if(B.size()>A.size()) return A;
		vector<int> rem,mod;
		int n,m;
		n=A.size()-1;
		m=B.size()-1;
		reverse(ALL(A));
		reverse(ALL(B));
		rem=A/B;
		reverse(ALL(A));
		reverse(ALL(B));
		rem.resize(n-m+1);
		reverse(ALL(rem));
		mod=A-rem*B;
		mod.resize(m);
		return mod;
	}
	vector<int> der(vector<int> A){
		while(A.size()!=1&&A.back()==0) A.POB();
		vector<int> ret(A.size()-1);
		rep(i,ret.size()) ret[i]=1ll*(i+1)*A[i+1]%MOD; 
		if(ret.empty()) return vector<int> (1,0);
		return ret;
	}
	class MC{// 
		vector<vector<int> > RAM;
		vector<vector<int> > SIN;
		vector<int> Lc;
		vector<int> Rc;
		vector<int> ret;
		vector<int> x_;
		void fendge1(int l,int r,int& cnt){
			if(l==r-1){
				Lc.PB(0);
				Rc.PB(0);
				RAM.PB(SIN[l]);
				return ;
			}
			RAM.PB(vector<int> (0));
			Lc.PB(0);
			Rc.PB(0);
			int now=cnt;
			int mid=(l+r)>>1;
			int L=++cnt;
			fendge1(l,mid,cnt);
			int R=++cnt;
			fendge1(mid,r,cnt);
			Lc[now]=L;
			Rc[now]=R;
			RAM[now]=RAM[L]*RAM[R];
		}
		void fendge2(int l,int r,int cnt,vector<int> p){
			p=p%RAM[cnt];
			if(r-l<=300){
				rb(i,l,r-1){
					  int T=1;
					rep(j,p.size()){
						ret[i]=qadd(ret[i],qmul(T,p[j]));
						T=qmul(T,x_[i]);
					}
				}
				return ;
			}
			int mid=(l+r)>>1;
			fendge2(l,mid,Lc[cnt],p);
			fendge2(mid,r,Rc[cnt],p); 
		}
		public:
			vector<int> init(vector<int> p,vector<int> x){
				x_=x;
				Lc.clear();
				Rc.clear();
				RAM.clear();
				SIN.clear();
				ret.clear();
				ret.resize(x.size());
				rep(i,x.size()){
					SIN.PB(vector<int>{(MOD-x[i]),1});
				}
				int cnt=0;
				fendge1(0,x.size(),cnt);
				fendge2(0,x.size(),0,p);
				return ret;
			}
	}mc;
	vector<int> multiple_calculation(vector<int> p,vector<int> x){
		return mc.init(p,x);	
	}
	class ITP{
		vector<int> u;
		vector<int> v;
		vector<int> fm;
		vector<int> fendge(int l,int r){
			if(l==r-1){return vector<int> {(MOD-u[l]),1};}
			int mid=(l+r)>>1;
			return fendge(l,mid)*fendge(mid,r);
		}
		pair<vector<int>,vector<int> > fendge2(int l,int r){
			if(l==r-1){
				return {vector<int> {(MOD-u[l]),1},vector<int> {fm[l]}};
			}
			int mid=(l+r)>>1;
			pair<vector<int>,vector<int> > L,R;
			L=fendge2(l,mid);
			R=fendge2(mid,r);
			return {L.FIR*R.FIR,L.FIR*R.SEC+R.FIR*L.SEC}; 
		}
		public:
			vector<int> solve(vector<mp> x){
				u.clear();
				v.clear();
				int n=x.size();
				for(auto it:x) u.PB(it.FIR),v.PB(it.SEC);
				vector<int> g=fendge(0,u.size());
				fm=multiple_calculation(der(g),u);
				rep(i,n){
					fm[i]=qmul(v[i],inv(fm[i]));
				}
				return fendge2(0,n).SEC;
			}
	}itp;
	vector<int> interpolation(vector<mp> x){
		return itp.solve(x);
	}
}
using namespace mypoly;
const int MAXN=5e4+1;
void add(int & A,int B){
    A+=B;
    if(A>=MOD) A-=MOD;
}
int n;
pair<int,vector<int> >/*answer for [n,m],answer for line*/ solve(int n,int m){
    if(m==1) {
        vector<int> ret(n+1,1);
        ret[0]=0;
        return II(1,ret);
    }
    pair<int,vector<int> > small=solve(n,m/2);
    int smallcyc=small.FIR;
    vector<int> smallline=small.SEC;
    smallline[1]=(m+1)/2;
    /*
    x: < m-m/2
    o: >= m-m/2
    */
    int anscyc=0;
    //calculate cycle answer
    if(n%2==0) add(anscyc,2ll*smallcyc%MOD);// case : oxox..oxox
    // case : [xoxox][xo..x..ox][xo..ox]
    vector<int> odd(n+1,0);
    rb(i,1,n) if(i&1) odd[i]=smallline[i];
    vector<int> orodd=odd;
    odd[0]=1;
    rb(i,1,n) odd[i]=(MOD-odd[i])%MOD;
    odd=poly.inverse(odd,n+1);
    rb(i,1,n) orodd[i]=1ll*i*orodd[i]%MOD;
    add(anscyc,(odd*orodd)[n]);
    //calculate line answer
    vector<int> ansline(n+1,0);
    vector<int> even(n+1,0);
    rb(i,1,n) if(i%2==0) even[i]=smallline[i];
    // case1 : [x..x] -> [xo..x..ox]..[xo..x..ox]..[xo..x..ox]
    rb(i,1,n) add(ansline[i],odd[i]);
    // case2 : [x..o]/[o..x] -> [xo..x..ox]..[xo..x..ox]..[xo..xo..xo]
    vector<int> tmp=even*odd;
    rb(i,1,n) add(ansline[i],2ll*tmp[i]%MOD);
    // case3 : [o..o] -> [oxox..ox]..[xo..oxo..ox]..[xo..xoxo]
    tmp=even*tmp;
    rb(i,1,n) add(ansline[i],tmp[i]);
    // case4 : [oxoxoxo]
    rb(i,1,n) if(i&1) add(ansline[i],smallline[i]);
    return II(anscyc,ansline);
}
int main(){
    int m;
    cin>>n>>m;
    cout<<solve(n,m).FIR<<endl;
    return 0;
}