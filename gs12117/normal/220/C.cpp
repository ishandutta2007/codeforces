#include<stdio.h>
#include<algorithm>
int n;
int a[100100];
int b[100100];
int al[100100];
int bl[100100];
int c[100100];
struct st{
	int loc,ep;
	bool operator<(const st&r)const{
		return loc<r.loc;
	}
};
st data[200100];
int stk[200100];
int sp;
int ans[100100];
int main(){
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		a[i]--;
		al[a[i]]=i;
	}
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
		b[i]--;
		bl[b[i]]=i;
	}
	for(i=0;i<n;i++){
		data[i*2].loc=al[i]-bl[i];
		data[i*2].ep=n-bl[i];
		if(al[i]-bl[i]<0){
			data[i*2+1].loc=al[i]-bl[i]+n;
			data[i*2+1].ep=2*n-bl[i];
		}
		else{
			data[i*2+1].loc=al[i]-bl[i]-n;
			data[i*2+1].ep=-bl[i];
		}
	}
	std::sort(data,data+2*n);
	j=0;
	for(i=0;i<n;i++){
		while(j<2*n&&data[j].loc<=i){
			while(sp!=0&&data[j].ep>=data[stk[sp-1]].ep)sp--;
			stk[sp]=j;
			sp++;
			j++;
		}
		while(sp!=0&&data[stk[sp-1]].ep<=i){
			sp--;
		}
		if(sp==0){
			ans[(n-i)%n]=99999999;
		}
		else{
			ans[(n-i)%n]=i-data[stk[sp-1]].loc;
		}
	}
	for(i=0;i<n;i++){
		c[i]=a[i];
	}
	for(i=0;i<n;i++){
		a[i]=c[n-i-1];
	}
	for(i=0;i<n;i++){
		c[i]=b[i];
	}
	for(i=0;i<n;i++){
		b[i]=c[n-i-1];
	}
	for(i=0;i<n;i++){
		al[a[i]]=i;
	}
	for(i=0;i<n;i++){
		bl[b[i]]=i;
	}
	for(i=0;i<n;i++){
		data[i*2].loc=al[i]-bl[i];
		data[i*2].ep=n-bl[i];
		if(al[i]-bl[i]<0){
			data[i*2+1].loc=al[i]-bl[i]+n;
			data[i*2+1].ep=2*n-bl[i];
		}
		else{
			data[i*2+1].loc=al[i]-bl[i]-n;
			data[i*2+1].ep=-bl[i];
		}
	}
	std::sort(data,data+2*n);
	j=0;
	for(i=0;i<n;i++){
		while(j<2*n&&data[j].loc<=i){
			while(sp!=0&&data[j].ep>=data[stk[sp-1]].ep)sp--;
			stk[sp]=j;
			sp++;
			j++;
		}
		while(sp!=0&&data[stk[sp-1]].ep<=i){
			sp--;
		}
		if(sp!=0&&i-data[stk[sp-1]].loc<ans[i]){
			ans[i]=i-data[stk[sp-1]].loc;
		}
	}
	for(i=0;i<n;i++){
		printf("%d\n",ans[i]);
	}
}