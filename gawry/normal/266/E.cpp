#include<cstdio>
#include<cstring>
const int MAX=100000;
const int MOD=1000000000+7;
const int POWER=(1<<17);
int power(int x,int n){
  int r=1;
  while(n--){
	  r=(long long)r*x%MOD;
	}
	return r;
}
int n,m,a[MAX],choose[20][20];
struct tree {
	int t[2*POWER],mult[2*POWER],delayed[2*POWER];
	tree(){
		memset(t,0,sizeof(t));
	  memset(mult,0,sizeof(mult));
		memset(delayed,-1,sizeof(delayed));
	}
	void delay(int pos,int val){
		delayed[pos]=val;
		  t[pos]=(long long)val*mult[pos]%MOD;
	}
	void fix_single(int pos){
    if(delayed[pos]>-1){
			if(pos<POWER){
				delay(2*pos,delayed[pos]);
				delay(2*pos+1,delayed[pos]);
			}
			delayed[pos]=-1;
		}
	}
	void fix(int pos){
	  if(!pos)return;
		fix(pos/2);
	  fix_single(pos);
	}
	void repair(int pos){
	  if(pos<POWER)t[pos]=(t[pos*2]+t[pos*2+1])%MOD;
	}
  void change(int from,int to,int val){
/*for(int i=from;i<=to;i++)t[i]=mult[i]*val;
return;*/
    from+=POWER;
		to+=POWER;
		fix(from);
		fix(to);
		delay(from,val);
		delay(to,val);
		while(from+1<to){
			repair(from);
			repair(to);
      if(from%2==0)delay(from+1,val);
			if(to%2)delay(to-1,val); 
			from/=2;
			to/=2;
		}
		while(from){
			repair(from);
			from/=2;
		}
		while(to){
			repair(to);
			to/=2;
		}
	}
	int sum(int from,int to){
    int ans=0;
/*for(int i=from;i<=to;i++)ans=(ans+t[i])%MOD;
return ans;*/
    from+=POWER;
		to+=POWER;
		fix(from);
		fix(to);
    ans=t[from];
		if(from<to)ans=(ans+t[to])%MOD;
		while(from+1<to){
			if(from%2==0){
				fix_single(from+1);
				ans=(ans+t[from+1])%MOD;
			}
			if(to%2){
				fix_single(to-1);
				ans=(ans+t[to-1])%MOD;
			}
			from/=2;
			to/=2;
		}
		return ans;
	}
} t[6];
main(){
	for(int i=0;i<19;i++){choose[i][0]=1;for(int j=0;j<i;j++)choose[i][j+1]=(choose[i-1][j]+choose[i-1][j+1])%MOD;}
  scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
  for(int k=0;k<=5;k++){
		for(int i=0;i<n;i++)t[k].mult[POWER+i]=power(i,k);
		for(int i=POWER-1;i;i--)t[k].mult[i]=(t[k].mult[2*i]+t[k].mult[2*i+1])%MOD;
	  for(int i=0;i<n;i++)t[k].change(i,i,a[i]);
	}
  while(m--){
		char op;
		int from,to,val;
		scanf(" %c %d %d %d",&op,&from,&to,&val);
    --from;--to;
    if(op=='='){
			for(int k=0;k<=5;k++)t[k].change(from,to,val);
		}else{
			int sum=0;
      for(int k=0;k<=val;k++)sum=(sum+(long long)choose[val][k]*t[k].sum(from,to)%MOD*power(MOD+1-from,val-k))%MOD;
			printf("%d\n",sum);
		}
	}
}