#include<stdio.h>
#include<vector>
char s[1000];
int mod=1000000007;
int n;
long long int ans;
int cond[20][5];
std::vector<int> andmerge(std::vector<int> xx,std::vector<int> yy){
	int i,j,k;
	std::vector<int> x,y,z;
	for(i=0;i<65536;i++){
		x.push_back(0);
		y.push_back(0);
		z.push_back(0);
	}
	for(i=0;i<65536;i++){
		x[i]=xx[i];
		y[i]=yy[i];
	}
	for(i=0;i<16;i++){
		for(j=0;j<65536;j++){
			if((j&(1<<i))==0){
				x[j]+=x[j+(1<<i)];
				x[j]%=mod;
				y[j]+=y[j+(1<<i)];
				y[j]%=mod;
			}
		}
	}
	for(i=0;i<65536;i++){
		z[i]=((long long int)x[i])*y[i]%mod;
	}
	for(i=0;i<16;i++){
		for(j=0;j<65536;j++){
			if((j&(1<<i))==0){
				z[j]+=mod-z[j+(1<<i)];
				z[j]%=mod;
			}
		}
	}
	return z;
}
std::vector<int> ormerge(std::vector<int> xx,std::vector<int> yy){
	int i,j,k;
	std::vector<int> x,y,z;
	for(i=0;i<65536;i++){
		x.push_back(0);
		y.push_back(0);
		z.push_back(0);
	}
	for(i=0;i<65536;i++){
		x[i]=xx[i];
		y[i]=yy[i];
	}
	for(i=0;i<16;i++){
		for(j=0;j<65536;j++){
			if((j&(1<<i))!=0){
				x[j]+=x[j-(1<<i)];
				x[j]%=mod;
				y[j]+=y[j-(1<<i)];
				y[j]%=mod;
			}
		}
	}
	for(i=0;i<65536;i++){
		z[i]=((long long int)x[i])*y[i]%mod;
	}
	for(i=0;i<16;i++){
		for(j=0;j<65536;j++){
			if((j&(1<<i))!=0){
				z[j]+=mod-z[j-(1<<i)];
				z[j]%=mod;
			}
		}
	}
	return z;
}
std::vector<int> f(int start,int end){
	std::vector<int>res;
	int i,j;
	for(i=0;i<65536;i++){
		res.push_back(0);
	}
	if(start==end){
		if(s[start]=='A'||s[start]=='?'){
			res[0xAAAA]++;
		}
		if(s[start]=='B'||s[start]=='?'){
			res[0xCCCC]++;
		}
		if(s[start]=='C'||s[start]=='?'){
			res[0xF0F0]++;
		}
		if(s[start]=='D'||s[start]=='?'){
			res[0xFF00]++;
		}
		if(s[start]=='a'||s[start]=='?'){
			res[0x5555]++;
		}
		if(s[start]=='b'||s[start]=='?'){
			res[0x3333]++;
		}
		if(s[start]=='c'||s[start]=='?'){
			res[0xF0F]++;
		}
		if(s[start]=='d'||s[start]=='?'){
			res[0xFF]++;
		}
	}
	else{
		j=0;
		for(i=start;;i++){
			if(s[i]=='(')j++;
			else if(s[i]==')')j--;
			else if(j==0){
				break;
			}
		}
		std::vector<int>lft,rht;
		lft=f(start+1,i-2);
		rht=f(i+2,end-1);
		if(s[i]=='&'){
			res=andmerge(lft,rht);
		}
		else if(s[i]=='|'){
			res=ormerge(lft,rht);
		}
		else{
			std::vector<int>tres;
			res=andmerge(lft,rht);
			tres=ormerge(lft,rht);
			for(i=0;i<65536;i++){
				res[i]+=tres[i];
				res[i]%=mod;
			}
		}
	}
	return res;
}
int main(){
	int i,j,k;
	scanf("%s",s);
	for(i=0;s[i];i++);
	std::vector<int> p=f(0,i-1);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d%d",&cond[i][0],&cond[i][1],&cond[i][2],&cond[i][3],&cond[i][4]);
	}
	for(i=0;i<65536;i++){
		for(j=0;j<n;j++){
			k=8*cond[j][3]+4*cond[j][2]+2*cond[j][1]+1*cond[j][0];
			if((i>>k)%2!=cond[j][4])break;
		}
		if(j==n){
			ans+=p[i];
			ans%=mod;
		}
	}
	printf("%I64d",ans);
}