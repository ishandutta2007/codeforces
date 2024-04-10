#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
///*(^(^(^(^(^o^)^)^)^)^) ('') */
int n,k,x[10000],y[1000]={},z[10010],s=0,ans[10001],w=0;
int main(){
	FILE *infile,*outfile;
	infile=fopen("input.txt","r");
	outfile=fopen("output.txt","w");
	fscanf(infile,"%d%d",&n,&k);
for(int i=0;i<n;i++){
	fscanf(infile,"%d",&x[i]);
}
for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		if(x[i]<x[j]){
			y[i]++;
		}}}
for(int i=0;i<n;i++){
	if(y[i]<=k-1){
		z[s]=i;
		s++;
	}}
for(int e=0;e<k;e++){
	for(int a=0;a<s;a++){
	if(y[z[a]]==e){
		ans[w]=z[a];
		w++;
	}}
if(w>=k){
	fprintf(outfile,"%d\n",x[ans[k-1]]);
	sort(ans,ans+k);
	fprintf(outfile,"%d",ans[0]+1);
	for(int g=1;g<k;g++){
		fprintf(outfile," %d",ans[g]+1);
	}
	printf("\n");
	goto wwww;
}}
wwww:;
return 0;
}