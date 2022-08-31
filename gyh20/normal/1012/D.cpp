#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,s1x[400002],s1y[400002],s2x[400002],s2y[400002],tp1,tp2,X[500002],Y[500002],Tx[500002],Ty[500002],Tp;
char A[200002],B[200002];
int main(){
	scanf("%s%s",A+1,B+1),n=strlen(A+1);
	for(re int i=n,l;i;i=l-1){
		l=i;
		while(l&&A[l-1]==A[l])--l;
		s1x[++tp1]=i-l+1,s1y[tp1]=A[l];
	}n=strlen(B+1);
	for(re int i=n,l;i;i=l-1){
		l=i;
		while(l&&B[l-1]==B[l])--l;
		s2x[++tp2]=i-l+1,s2y[tp2]=B[l];
	}
	while(tp1>1||tp2>1){
		++m;
		if(s1y[tp1]!=s2y[tp2]&&tp1!=1&&tp2!=1){
			if(abs(tp1-tp2)<=1){
				X[m]=s1x[tp1],Y[m]=s2x[tp2];
				swap(s1x[tp1],s2x[tp2]);
				swap(s1y[tp1],s2y[tp2]);
				while(tp1&&s1y[tp1]==s1y[tp1-1])s1x[tp1-1]+=s1x[tp1],--tp1;
				while(tp2&&s2y[tp2]==s2y[tp2-1])s2x[tp2-1]+=s2x[tp2],--tp2;
			}
			else if(tp1>tp2+1){
				Tp=0;
				re int oo=tp1+tp2>>1;
				for(re int i=tp1;i-2>=oo;i-=2)Tx[++Tp]=s1x[i],Ty[Tp]=s1y[i],Tx[++Tp]=s1x[i-1],Ty[Tp]=s1y[i-1],X[m]+=s1x[i]+s1x[i-1],tp1=i-2;
				X[m]+=s1x[tp1],Y[m]=s2x[tp2];
				swap(s1x[tp1],s2x[tp2]);
				swap(s1y[tp1],s2y[tp2]);
				while(tp1&&s1y[tp1]==s1y[tp1-1])s1x[tp1-1]+=s1x[tp1],--tp1;
				while(tp2&&s2y[tp2]==s2y[tp2-1])s2x[tp2-1]+=s2x[tp2],--tp2;
				for(re int i=Tp;i;--i)s2x[++tp2]=Tx[i],s2y[tp2]=Ty[i];
			}
			else{
				Tp=0;
				re int oo=tp1+tp2>>1;
				for(re int i=tp2;i-2>=oo;i-=2)Tx[++Tp]=s2x[i],Ty[Tp]=s2y[i],Tx[++Tp]=s2x[i-1],Ty[Tp]=s2y[i-1],Y[m]+=s2x[i]+s2x[i-1],tp2=i-2;
				Y[m]+=s2x[tp2],X[m]=s1x[tp1];
				swap(s1x[tp1],s2x[tp2]);
				swap(s1y[tp1],s2y[tp2]);
				while(tp1&&s1y[tp1]==s1y[tp1-1])s1x[tp1-1]+=s1x[tp1],--tp1;
				while(tp2&&s2y[tp2]==s2y[tp2-1])s2x[tp2-1]+=s2x[tp2],--tp2;
				for(re int i=Tp;i;--i)s1x[++tp1]=Tx[i],s1y[tp1]=Ty[i];
				
			}
		}
		else{
			if(tp1!=1&&tp2!=1){
				if(tp1==2&&tp2==2){
					X[m]=0,Y[m]=s2x[tp2];
					s1x[tp1]+=s2x[tp2],--tp2;
					continue;
				}
				if(tp1>tp2){
					X[m]=s1x[tp1]+s1x[tp1-1],Y[m]=s2x[tp2];
					s2x[tp2-1]+=s1x[tp1-1],s1x[tp1-2]+=s2x[tp2],s2x[tp2]=s1x[tp1],tp1-=2;
				}
				else{
					Y[m]=s2x[tp2]+s2x[tp2-1],X[m]=s1x[tp1];
					s1x[tp1-1]+=s2x[tp2-1],s2x[tp2-2]+=s1x[tp1],s1x[tp1]=s2x[tp2],tp2-=2;
				}
			}
			else{
				if(tp1==1){
					re int o=tp2>>1;
					while(s2y[o]!=s1y[1])++o;
					if(o+o<=tp2){
						X[m]=s1x[1];
						s2x[o]+=s1x[1],tp1=0;
						for(re int i=o+1;i<=tp2;++i)s1x[++tp1]=s2x[i],s1y[tp1]=s2y[i],Y[m]+=s2x[i];
						tp2=o;
					}
					else{
						X[m]=0,Y[m]=s2x[o];
						s1x[1]+=s2x[o];
						for(re int i=o+1;i<=tp2;++i)s1x[++tp1]=s2x[i],s1y[tp1]=s2y[i],Y[m]+=s2x[i];
						tp2=o-1;
					}
				}
				else{
					re int o=tp1>>1;
					while(s1y[o]!=s2y[1])++o;
					if(o+o<=tp1){
						Y[m]=s2x[1];
						s1x[o]+=s2x[1],tp2=0;
						for(re int i=o+1;i<=tp1;++i)s2x[++tp2]=s1x[i],s2y[tp2]=s1y[i],X[m]+=s1x[i];
						tp1=o;
					}
					else{
						Y[m]=0,X[m]=s1x[o];
						s2x[1]+=s1x[o];
						for(re int i=o+1;i<=tp1;++i)s2x[++tp2]=s1x[i],s2y[tp2]=s1y[i],X[m]+=s1x[i];
						tp1=o-1;
					}
				}
			}
		}
	}
	printf("%d\n",m);
	for(re int i=1;i<=m;++i)printf("%d %d\n",X[i],Y[i]);
}