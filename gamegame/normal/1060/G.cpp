#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int n,q;
ll a[100002];
struct magic{
	ll st,len;
	ll rnd,des;
	bool operator<(const magic& b) const{
		return st<b.st;
	}
};
vector<magic>cool[262144];
void build(int id,int l,int r){
	if(l==r){
		ll num=(a[l+1]-a[l])/l,num2=(a[l+1]-a[l])%l;
		if(num2==0){
			magic tmp={a[l],l,num,a[l+1]};
			cool[id].push_back(tmp);
		}
		else{
			magic tmp={a[l],num2,num+1,(num+1)*l+a[l]};
			cool[id].push_back(tmp);
			tmp={a[l]+num2,l-num2,num,a[l+1]};
			cool[id].push_back(tmp);
		}
		/*cout << id << ' ' << l << ' ' << r << ": \n";
		for(auto cur:cool[id]){
			cout << cur.st << ' ' << cur.len << ' ' << cur.rnd << ' ' << cur.des << endl;
		}
		cout << endl;*/
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	for(magic cur:cool[id*2]){
		magic tmp={cur.des+1,0,0,0};
		int pos=lower_bound(cool[id*2+1].begin(),cool[id*2+1].end(),tmp)-cool[id*2+1].begin()-1;
		ll did=0;
		while(true){
			magic lol=cool[id*2+1][pos];
			if(lol.st<cur.des+did){
				ll tmp=cur.des+did-lol.st;
				lol.st+=tmp;
				lol.len-=tmp;
				lol.des+=tmp;
			}
			if(did+lol.len>cur.len){
				ll tmp=did+lol.len-cur.len;
				lol.len-=tmp;
			}
			magic newi={cur.st+did,lol.len,cur.rnd+lol.rnd,lol.des};
			cool[id].push_back(newi);
			did+=lol.len;
			pos++;
			if(did==cur.len) break;
		}
	}
	/*cout << id << ' ' << l << ' ' << r << ": \n";
	for(auto cur:cool[id]){
		cout << cur.st << ' ' << cur.len << ' ' << cur.rnd << ' ' << cur.des << endl;
	}
	cout << endl;*/
}
ll x,k;
int pos;
bool solve(int id,int l,int r){
	if(pos==l){
		magic tmp={x+1,0,0,0};
		int pos2=lower_bound(cool[id].begin(),cool[id].end(),tmp)-cool[id].begin()-1;
		if(k>=cool[id][pos2].rnd){
			k-=cool[id][pos2].rnd;
			x=cool[id][pos2].des+x-cool[id][pos2].st;
			pos=r+1;
			return false;
		}
	}
	if(l==r) return true;
	int mid=(l+r)/2;
	if(pos>mid){
		return solve(id*2+1,mid+1,r);
	}
	if(solve(id*2,l,mid)) return true;
	return solve(id*2+1,mid+1,r);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		a[i]=a[i]-i+1;
	}
	a[n+1]=1e18;
	build(1,1,n);
	for(int i=1; i<=q ;i++){
		cin >> x >> k;
		if(x<a[1]){
			cout << x << '\n';
			continue;
		}
		pos=lower_bound(a+1,a+n+1,x+1)-a-1;
		ll num=(a[pos+1]-x+pos-1)/pos;
		if(num>k){
			cout << x+k*pos << '\n';
			continue;
		}
		k-=num;
		x+=num*pos;
		pos++;
		solve(1,1,n);
		x+=k*pos;
		cout << x << '\n';
	}
}