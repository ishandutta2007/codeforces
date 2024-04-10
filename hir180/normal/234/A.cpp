
#include  <cstdio>
using  namespace std;
int n,y[10000][2]; char x[10001];
int main(){
FILE *infile,*outfile;
infile=fopen("input.txt","r");
outfile=fopen("output.txt","w");
fscanf(infile,"%d",&n);
fscanf(infile,"%s",x);

for(int i=0;i<n/2;i++){
if(x[i]=='R'  && x[i+n/2]=='L'){
y[i][0]=i+n/2+1;
y[i][1]=i+1;
}else{
y[i][1]=i+n/2+1;
y[i][0]=i+1;
}}
for(int i=0;i<n/2;i++){
fprintf(outfile,"%d %d\n",y[i][0],y[i][1]);
}
return 0;

}