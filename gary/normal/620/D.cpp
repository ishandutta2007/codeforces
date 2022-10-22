//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(LL a=b;a<=c;++a)
#define rl(a,b,c) for(LL a=b;a>=c;--a)
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
const LL INF=0x3f3f3f3f;
typedef pair<LL,LL> mp;
typedef pair<mp,mp> superpair;
LL a[2000+10],b[2000+10];
struct craft{
	LL val;
	LL fi;
	LL se;
};
vector<craft> v;
map<mp,LL> num;
LL suma,sumb;
bool cmp(craft A,craft B){
	return A.val<B.val;
}
struct mine{
	LL SUMA,SUMB;
	vector<mp> V;
}final;
vector<LL> Copy;
int main(){
//	FREO;
	LL n,m;
	scanf("%I64d",&n);
	rb(i,1,n){
		scanf("%I64d",&a[i]);
		suma+=a[i];
	}
	scanf("%I64d",&m);
	rb(i,1,m){
		scanf("%I64d",&b[i]);
		sumb+=b[i];
	}
	craft tmp;
	rb(i,1,n){
		rb(j,1,m){
			tmp.val=b[j]-a[i];
			tmp.fi=i;//a;
			tmp.se=j;//b;
			v.PB(tmp);
		}
	}
	sort(v.begin(),v.end(),cmp);
	LL tmp_sum_a,tmp_sum_b;
	LL SZ=v.size();
//	cout<<SZ<<endl;
	rep(i,SZ){
		Copy.PB(v[i].val);
	} 
	final.SUMA=suma;
	final.SUMB=sumb; 
	vector<LL> :: IT ite;
	rep(i,SZ){
		tmp_sum_a=suma+v[i].val;
		tmp_sum_b=sumb-v[i].val;
//		cout<<v[i].fi<<" "<<v[i].se<<endl;
		if(abs(tmp_sum_a-tmp_sum_b)<abs(final.SUMA-final.SUMB)){
			final.SUMA=tmp_sum_a;
			final.SUMB=tmp_sum_b;
			final.V.clear();
			final.V.PB(II(v[i].fi,v[i].se));
		}
		ite=lower_bound(Copy.begin(),Copy.end(),(-(tmp_sum_a-tmp_sum_b))/2);
		if(ite==Copy.end()){
			ite--;
		}
		LL now=ite-Copy.begin();
//		cout<<now<<endl;
		rb(j,now,SZ-1){
//			cout<<j<<endl;
			if(v[j].fi!=v[i].fi&&v[j].se!=v[i].se){
				LL tmptmp_sum_a,tmptmp_sum_b;
				tmptmp_sum_a=tmp_sum_a+v[j].val;
				tmptmp_sum_b=tmp_sum_b-v[j].val;
				if(abs(tmptmp_sum_a-tmptmp_sum_b)<abs(final.SUMA-final.SUMB)){
					final.SUMA=tmptmp_sum_a;
					final.SUMB=tmptmp_sum_b;
					final.V.clear();
					final.V.PB(II(v[i].fi,v[i].se));
					final.V.PB(II(v[j].fi,v[j].se));
//				 	cout<<now<<"j"<<j<<" "<<v[j].fi<<" follow "<<v[j].se<<endl;
				}
				else{
//					cout<<v[j].fi<<" follow "<<v[j].se<<"but_no1"<<endl;
				}
				break;
			}
			else{
//				cout<<v[j].fi<<" follow "<<v[j].se<<"but_no2"<<endl;
			}
		}
		rl(j,now,0){
//			cout<<j<<endl;
			if(v[j].fi!=v[i].fi&&v[j].se!=v[i].se){
				LL tmptmp_sum_a,tmptmp_sum_b;
				tmptmp_sum_a=tmp_sum_a+v[j].val;
				tmptmp_sum_b=tmp_sum_b-v[j].val;
				if(abs(tmptmp_sum_a-tmptmp_sum_b)<abs(final.SUMA-final.SUMB)){
					final.SUMA=tmptmp_sum_a;
					final.SUMB=tmptmp_sum_b;
					final.V.clear();
					final.V.PB(II(v[i].fi,v[i].se));
					final.V.PB(II(v[j].fi,v[j].se));
//					cout<<now<<"j"<<j<<v[j].fi<<" follow "<<v[j].se<<endl;
				}
				else{
//					cout<<v[j].fi<<" follow "<<v[j].se<<"but_no1"<<endl;
				}
				break;
			}
			else{
//				cout<<v[j].fi<<" follow "<<v[j].se<<"but_no2"<<endl;
			}
		}
//		cout<<"end------------------------------------------------------------------------"<<endl;
	}
	printf("%I64d\n%I64d\n",abs(final.SUMA-final.SUMB),(LL)(final.V.size()));
	LL SSZ=(LL)(final.V.size());
	rep(i,SSZ){
		printf("%I64d %I64d\n",final.V[i].FIR,final.V[i].SEC);
	}
	return 0;
}