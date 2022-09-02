#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int num[100005];
int n,m;
int main(){
scanf("%d %d",&n,&m);
for(int i=0;i<n;i++){
scanf("%d",&num[i]);
}
vector<int> de,in;
for(int i=0;i<n-1;i++){
if(num[i]<num[i+1]){
in.push_back(i);
}else if(num[i+1]<num[i]){
de.push_back(i);
}
}
for(int i=0;i<m;i++){
int a,b; 
scanf("%d %d",&a,&b);
a--; b--;
int wp=lower_bound(de.begin(),de.end(),a)-de.begin();
int ww=lower_bound(in.begin(),in.end(),a)-in.begin();
if(wp==de.size() || ww==in.size()){
	puts("Yes");
	continue;
}else{
int wp1=lower_bound(de.begin(),de.end(),b)-de.begin();
int ww1=lower_bound(in.begin(),in.end(),b)-in.begin();
wp1--; ww1--;
int a=(wp1-wp+1);
int b=(ww1-ww+1);
if(a==0 || b==0 ){
	puts("Yes");
continue;
}else{
	bool ok=true;
	int w2=in[ww1];
	int w3=de[wp];
	if(w2<w3){
		puts("Yes");
	}else{
		puts("No");
	}
}
}
}
return 0;
}