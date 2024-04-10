#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
class matrix{
public:
	int n;
	vector<vi> val;
	matrix(int n=2);
	matrix operator+(const matrix&) const;
	matrix operator-(const matrix&) const;
	matrix operator*(const matrix&) const;
	matrix& operator=(const matrix& b){
		val=b.val;
		n=b.n;
		return *this;
	}
	void set(int x){
		rep(i,0,n){
			rep(j,0,n){
				val[i][j]=x;
			}
		}
	}
	void print(){
		rep(i,0,n){
			rep(j,0,n){
				cout<<val[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	matrix mul(int a){
		matrix ans(this->n);
		rep(i,0,this->n){
			rep(j,0,this->n){
				ans.val[i][j]=a*this->val[i][j];
			}
		}
		return ans;
	}
};
matrix::matrix(int x){
	n=x;
	val.resize(x);
	rep(i,0,x){
		val[i].resize(x);
	}
}
matrix matrix::operator+(const matrix& b) const{
	matrix ans(b.n);
	rep(i,0,b.n){
		rep(j,0,b.n){
			ans.val[i][j]=this->val[i][j]+b.val[i][j];
		}
	}
	return ans;
}
matrix matrix::operator-(const matrix& b) const{
	matrix ans(b.n);
	rep(i,0,b.n){
		rep(j,0,b.n){
			ans.val[i][j]=this->val[i][j]-b.val[i][j];
		}
	}
	return ans;
}
matrix matrix::operator*(const matrix& b) const{
	matrix ans(b.n);
	rep(i,0,b.n){
		rep(j,0,b.n){
			rep(k,0,b.n){
				ans.val[i][j]+=this->val[i][k]*b.val[k][j];
				ans.val[i][j]%=hell;
			}
		}
	}
	return ans;			
}
matrix identity(int N=2){
	matrix ans(N);
	rep(i,0,N){
		ans.val[i][i]=1;
	}
	return ans;
}
matrix matexpo(matrix a, int n){
	if(n==0){
		return identity(a.n);
	}
	if(n==1) return a;
	matrix x=matexpo(a,n/2);
	matrix r=x*x;
	if(n&1) r=r*a;
	return r;
}
void solve(){
    matrix mat(4);
    rep(i,0,4){
    	rep(j,0,4){
    		mat.val[i][j]=i!=j;
    	}
    }
    int n;
    cin>>n;
    mat=matexpo(mat,n);
    cout<<mat.val[0][0]<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}