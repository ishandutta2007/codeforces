/*
	GaryMr
	Hurrah a contest at 5:35 Pm.!
		*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
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
LL a,b,m;
LL r[55];
bool check(int x){
	LL _there=1;
	LL tmp_mi;
//	if(x==34) cout<<(1<<(x-5))<<endl;
	rb(i,1,x-2){
		_there*=2;
	}
	tmp_mi=_there;
//	_there*=a;
	LL shang=b/a;
	if(b%a) shang++;
//	if(x==4) cout<<shang<<" "<<_there<<endl;
	if(shang<_there) return false;
	_there*=a;
	b-=_there;
	LL JIA=0;
	LL tmptmp=tmp_mi;
	rl(i,x-3,1){
		tmptmp/=2;
		JIA+=(tmptmp);
	}
//	if(x==11) cout<<JIA<<" "<<b<<endl;
	if(b-JIA<2) return false;
	rl(i,x-3,1){
		tmp_mi/=2;
		LL NEED=b/(tmp_mi);
//		if(x==11)cout<<NEED<<" "<<m<<endl;
		NEED=min(NEED,m);
		b-=NEED*(tmp_mi);
	}
//	if(x==34) cout<<b<<endl;
	if(b<=2*m){
		return true;
	}
	return false;
}
void print(int x){
	cout<<a<<" ";
	LL _there=1;
	rb(i,1,x-2){
		_there*=2;
	}
	LL tmp_mi=_there;
	_there*=a;
	b-=_there;
	LL JIA=0;
	LL tmptmp=tmp_mi;
	rl(i,x-3,1){
		tmptmp/=2;
		JIA+=(tmptmp);
	}
	rl(i,x-3,1){
	tmp_mi/=2;		
		JIA-=(tmp_mi);
		LL PLA=b-JIA-2;
		LL NEED=b/(tmp_mi);
		NEED=min(NEED,PLA/(tmp_mi));
		NEED=min(NEED,m);
		r[x-2-i+1]=NEED;
		b-=NEED*(tmp_mi);
	}
	LL sum=a;
	LL last1=b/2,last2=b-last1;
	r[x-1]=last1;
	r[x]=last2; 
	rb(i,2,x){
		LL tmp_a=sum+r[i];
		cout<<tmp_a<<" ";
		sum+=tmp_a;
	}
}
int main(){
	ios::sync_with_stdio(false);
//	freopen("Gary.out","w",stdout);
	int q;
	cin>>q;
	rb(SH,1,q){
	cin>>a>>b>>m;
	LL tmpb=b;
	if(b-a==0) {
		cout<<1<<" "<<a<<endl;
		continue;
	}
	if(b-a<=m){
		cout<<2<<" "<<a<<" "<<b<<endl;
		continue;
	}
	bool OK=0;
	rb(i,3,50){
		if(OK) break;
		b=tmpb;
		if(check(i)){
//			cout<<i<<" "<<endl;
			OK=1;
			cout<<i<<" ";
			b=tmpb;
			print(i);
			cout<<endl;
			break;
		}
	}
	
	b=tmpb;
	if(!OK){
		cout<<-1<<endl;
	}
	}

	return 0;
}