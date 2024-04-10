#include<stdio.h>
long long int c;
long long int ha,hb,wa,wb;
long long int ans;
long long int tans;
int main(){
	long long int i,t;
	scanf("%I64d%I64d%I64d%I64d%I64d",&c,&ha,&hb,&wa,&wb);
	if(ha*wb<hb*wa){
		t=ha;
		ha=hb;
		hb=t;
		t=wa;
		wa=wb;
		wb=t;
	}
	ans=0;
	if(wa>10000){
		for(i=0;i*wa<=c;i++){
			tans=i*ha;
			tans+=((c-i*wa)/wb)*hb;
			if(tans>ans)ans=tans;
		}
	}
	else{
		for(i=0;i<wa;i++){
			if(c-i*wb<0)break;
			tans=i*hb;
			tans+=((c-i*wb)/wa)*ha;
			if(tans>ans)ans=tans;
		}
	}
	printf("%I64d",ans);
}