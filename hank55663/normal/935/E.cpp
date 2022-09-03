#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
int mod=1e9+7;
int pp,mm;
char c[10004];
int i;
pair<vector<int>,vector<int> > E(){
	if(c[i]=='('){
		i++;
		auto p1 = E();
		i++;
		auto p2 =E();
		i++;
		vector<int> Max(p1.x.size()+p2.x.size()+1,-1e9);
		vector<int> Min(p1.x.size()+p2.x.size()+1,1e9);
		if(pp>mm){
			for(int i = 0 ;i<p1.x.size();i++){
				for(int j =0;j<p2.x.size();j++){
					Max[i+j]=max(Max[i+j],p1.x[i]+p2.x[j]);
					Min[i+j]=min(Min[i+j],p1.y[i]+p2.y[j]);
					Max[i+1+j]=max(Max[i+j+1],p1.x[i]-p2.y[j]);
					Min[i+j+1]=min(Min[i+j+1],p1.y[i]-p2.x[j]);
				}
			}
		}
		else{
			for(int i = 0 ;i<p1.x.size();i++){
				for(int j =0;j<p2.x.size();j++){
					Max[i+j+1]=max(Max[i+j+1],p1.x[i]+p2.x[j]);
					Min[i+j+1]=min(Min[i+j+1],p1.y[i]+p2.y[j]);
					Max[i+j]=max(Max[i+j],p1.x[i]-p2.y[j]);
					Min[i+j]=min(Min[i+j],p1.y[i]-p2.x[j]);
				}
			}
		}
		while(Max.size()-1>min(pp,mm)){
			Max.pop_back();
			Min.pop_back();
		}
		return mp(Max,Min);
	}
	else{
		i++;
		return mp(vector<int>{c[i-1]-'0'},vector<int>{c[i-1]-'0'});
	}
}
int main(){
	scanf("%s",c);
	scanf("%d %d",&pp,&mm);
	i=0;
	auto p = E();
	printf("%d\n",p.x[min(pp,mm)]);
}