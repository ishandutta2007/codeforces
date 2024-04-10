#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
using namespace std;
#define pb push_back
#define ll long long
#define ld long double
#define vi vector<int>
#define pii pair<int,int>
#define mp make_pair
#define st first
#define nd second
const int nax=1000123;

int n,m,zbuduj,reg;
int gr[nax],ilegr;

struct stru
{
	vi ludzie;
	int ile;
	ll suma;
};

stru grupa[nax];

int NIE()
{
	printf("NO");
	return 0;
}
int heh1=-1,heh2=-1;

int zlacz(int a, int b, ll dl)
{
	heh1=a;heh2=b;
	if(grupa[a].ile<grupa[b].ile)swap(a,b);
	// a liczniejsze
	for(int i=0;i<grupa[b].ile;++i){
		int x=grupa[b].ludzie[i];
		gr[x]=a;
		grupa[a].ludzie.pb(x);
	}
	grupa[a].ile+=grupa[b].ile;
	grupa[a].suma+=grupa[b].suma+dl;
	ilegr--;
	return 0;
}

struct cmp
{
	bool operator()(int a, int b)
	{
		if(grupa[a].suma!=grupa[b].suma)return grupa[a].suma<grupa[b].suma;
		return a<b;
	}
};

set<int,cmp> s;
set<int,cmp>::iterator it,it2;

ll miliard=1e9;

vector<pii > RES;
int main()
{
	scanf("%d%d%d%d",&n,&m,&zbuduj,&reg);
	ilegr=n;
	for(int i=1;i<=n;++i){
		gr[i]=i;
		vi w;
		w.pb(i);
		grupa[i].ludzie=w;
		grupa[i].ile=1;
		grupa[i].suma=0LL;
	}
	while(m--){
		int a,b,dl;
		scanf("%d%d%d",&a,&b,&dl);
		if(gr[a]==gr[b])grupa[gr[a]].suma+=(ll)dl;
		else zlacz(gr[a],gr[b],dl);
	}
	if(ilegr<reg)return NIE();
	for(int i=1;i<=n;++i)s.insert(gr[i]);
	//if(s.size()!=ilegr)printf("smietana\n");
	//printf("%d %d\n",s.size(),ilegr);
	// printf s.size powinien dac liczbe regionow
	while(zbuduj--){
		if(ilegr>reg){
			if(s.size()<2)return NIE();
			it=s.begin();
			it2=it;
			it2++;
			int a=*it,b=*it2;
			s.erase(it);s.erase(it2);
			RES.pb(mp(a,b));
			zlacz(a,b,min(miliard,1LL+grupa[a].suma+grupa[b].suma));
			s.insert(gr[a]); //=gr[b]
		}
		else{
			bool q=1;
			/*if(s.size()>=2){
				it=s.begin();
				it2=it;
				it2++;
				int a=*it,b=*it2;
				if(1LL+grupa[a].suma+grupa[b].suma<=1000LL){
					s.erase(it);s.erase(it2);
					RES.pb(mp(a,b));
					zlacz(a,b,min(miliard,1LL+grupa[a].suma+grupa[b].suma));
					s.insert(gr[a]); //=gr[b]
					q=0;
				}
			}*/
			if(q){
				if(heh1==-1)return NIE();
				RES.pb(mp(heh1,heh2));
			}
		}
	}
	if(ilegr!=reg)return NIE();
	printf("YES\n");
	int po=RES.size();
	for(int i=0;i<po;++i)
		printf("%d %d\n",RES[i].st,RES[i].nd);
			
			
	return 0;
}