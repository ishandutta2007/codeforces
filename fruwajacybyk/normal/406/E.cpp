#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

using namespace std;

int ilemin(VI v){
	int x=v[0];
	int res = 1;
	FOR(i,1,v.size()){
		if(v[i]==x) res++;
		else return res;
	}
	return res;
}

int ilemax(VI v){
	int x = v[v.size()-1];
	int res = 1;
	for(int i=v.size()-2;i>=0;i--){
		if(v[i]==x) res++;
		else return res;
	}
	return res;
}

void do1(VI v){
			int a = ilemin(v);
			int b = ilemax(v);
			if(v[0]==v[v.size()-1]){
				lint res = (a*1LL*(a-1)*1LL*(a-2))/6LL;
				cout<<res<<endl;
			}
			else{
				int c = v.size()-a-b;
				lint res = a*1LL*b*1LL*c + ((a*1LL*(a-1))*1LL*b)/2LL + ((b*1LL*(b-1)*1LL*a))/2LL;
				cout<<res<<endl;
			}
}

void do2(){

}



int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	VI zero;
	VI one;
	FOR(i,0,m){
		int u,x;
		scanf("%d%d",&u,&x);
		if(u==1) one.pb(x);
		else zero.pb(x);
	}
	
	int Z = zero.size();
	int O = one.size();
	
	sort(zero.begin(),zero.end());
	sort(one.begin(),one.end());
	if( Z==0 || O == 0){
		if(Z==0){
			do1(one);
			return 0;
		}
		else{
			do1(zero);
			return 0;
		}
	}


	if(zero[Z-1]< one[0]){
		int dziura = one[0]-zero[Z-1];
		FOR(i,0,one.size()){
			one[i]-=dziura; 
		}
	}
	else if(one[O-1]<zero[0]){
		int dziura = zero[0]-one[O-1];
		FOR(i,0,one.size()){
			zero[i]-=dziura; 
		}
	}

	lint res = 0;
	
	FOR(i,0,zero.size()){
		VI::iterator it1 = lower_bound(one.begin(),one.end(),zero[i]);
		VI::iterator it2 = upper_bound(one.begin(),one.end(),zero[i]);
		int a = (it1-one.begin());
		int b = (it2-it1);
		int c = (one.end()-it2);
		res+= a*1LL*c;
		res+= a*1LL*b;
		res+= b*1LL*c;
		res+= (b*1LL*(b-1))/2LL;
	}

	FOR(i,0,one.size()){
		VI::iterator it1 = lower_bound(zero.begin(),zero.end(),one[i]);
		VI::iterator it2 = upper_bound(zero.begin(),zero.end(),one[i]);
		int a = (it1-zero.begin());
		int b = (it2-it1);
		int c = (zero.end()-it2);
		res+= a*1LL*c;
		res+= a*1LL*b;
		res+= b*1LL*c;
		res+= (b*1LL*(b-1))/2LL;
	}
	cout<<res<<endl;
	return 0;
}