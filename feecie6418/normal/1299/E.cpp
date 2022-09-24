#include<bits/stdc++.h>
using namespace std;
int n,a[1005],pos[1005],mod[10][1005];
void Find(int val){
	for(int i=1,has1=0,x;i<=n;i++){
		if(a[i])continue;
		cout<<"? "<<n-(val-1)*2-1<<' ';
		for(int j=1;j<=n;j++)if((!a[j]||a[j]==val||a[j]==n-val+1)&&j!=i)cout<<j<<' ';
		cout<<endl,cin>>x;
		if(x){
			if(val==1){
				if(!has1)has1=1,a[i]=1,pos[1]=i;
				else a[i]=n,pos[n]=i;
			}
			else {
				if(val%2==mod[2][i])a[i]=val,pos[val]=i;
				else a[i]=n-val+1,pos[n-val+1]=i;
			}
		}
	}
}
int main(){
	cin>>n,Find(1);
	for(int i=1,x;i<=n;i++)if(i!=pos[1])cout<<"? 2 "<<pos[1]<<' '<<i<<endl,cin>>x,mod[2][i]=x;
	for(int i=2;i<=4&&i*2<=n;i++)Find(i);
	if(n<=8){
		if(a[1]*2>n)for(int i=1;i<=n;i++)a[i]=n-a[i]+1;
		cout<<"! ";
		for(int i=1;i<=n;i++)cout<<a[i]<<' ';
		cout<<endl;
		return 0;
	}
	for(int i=1,x;i<=n;i++){//Find a[i]%3
		if(a[i])continue;
		cout<<"? 3 "<<pos[1]<<' '<<pos[2]<<' '<<i<<endl,cin>>x;
		if(x)continue;
		cout<<"? 3 "<<pos[2]<<' '<<pos[3]<<' '<<i<<endl,cin>>x;
		if(x)mod[3][i]=1;
		else mod[3][i]=2;
	}
	for(int i=1,x;i<=n;i++){//Find a[i]%5
		if(a[i])continue;
		cout<<"? 5 "<<pos[1]<<' '<<pos[2]<<' '<<pos[3]<<' '<<pos[n]<<' '<<i<<endl,cin>>x;
		if(x){
			mod[5][i]=((-n-6)%5+5)%5;
			continue;
		}
		cout<<"? 5 "<<pos[1]<<' '<<pos[2]<<' '<<pos[4]<<' '<<pos[n]<<' '<<i<<endl,cin>>x;
		if(x){
			mod[5][i]=((-n-7)%5+5)%5;
			continue;
		}
		cout<<"? 5 "<<pos[1]<<' '<<pos[3]<<' '<<pos[4]<<' '<<pos[n]<<' '<<i<<endl,cin>>x;
		if(x){
			mod[5][i]=((-n-8)%5+5)%5;
			continue;
		}
		cout<<"? 5 "<<pos[2]<<' '<<pos[3]<<' '<<pos[4]<<' '<<pos[n]<<' '<<i<<endl,cin>>x;
		if(x)mod[5][i]=((-n-9)%5+5)%5;
		else mod[5][i]=((-n)%5+5)%5;
	}
	for(int i=1,x;i<=n;i++){//Find a[i]%7
		if(a[i])continue;
		cout<<"? 7 "<<pos[1]<<' '<<pos[2]<<' '<<pos[3]<<' '<<pos[n-3]<<' '<<pos[n-2]<<' '<<pos[n-1]<<' '<<i<<endl;
		cin>>x;
		if(x){
			mod[7][i]=((-1-2-3-n+1-n+2-n+3)%7+7)%7;
			continue;
		}
		cout<<"? 7 "<<pos[1]<<' '<<pos[2]<<' '<<pos[3]<<' '<<pos[n-3]<<' '<<pos[n-2]<<' '<<pos[n]<<' '<<i<<endl,cin>>x;
		if(x){
			mod[7][i]=((-1-2-3-n+1-n+2-n+3-1)%7+7)%7;
			continue;
		}
		cout<<"? 7 "<<pos[1]<<' '<<pos[2]<<' '<<pos[3]<<' '<<pos[n-3]<<' '<<pos[n-1]<<' '<<pos[n]<<' '<<i<<endl,cin>>x;
		if(x){
			mod[7][i]=((-1-2-3-n+1-n+2-n+3-2)%7+7)%7;
			continue;
		}
		cout<<"? 7 "<<pos[1]<<' '<<pos[2]<<' '<<pos[3]<<' '<<pos[n-2]<<' '<<pos[n-1]<<' '<<pos[n]<<' '<<i<<endl,cin>>x;
		if(x){
			mod[7][i]=((-1-2-3-n+1-n+2-n+3-3)%7+7)%7;
			continue;
		}
		cout<<"? 7 "<<pos[1]<<' '<<pos[2]<<' '<<pos[4]<<' '<<pos[n-2]<<' '<<pos[n-1]<<' '<<pos[n]<<' '<<i<<endl,cin>>x;
		if(x){
			mod[7][i]=((-1-2-3-n+1-n+2-n+3-4)%7+7)%7;
			continue;
		}
		cout<<"? 7 "<<pos[1]<<' '<<pos[3]<<' '<<pos[4]<<' '<<pos[n-2]<<' '<<pos[n-1]<<' '<<pos[n]<<' '<<i<<endl,cin>>x;
		if(x)mod[7][i]=((-1-2-3-n+1-n+2-n+3-5)%7+7)%7;
		else mod[7][i]=((-1-2-3-n+1-n+2-n+3-6)%7+7)%7;
	}
	for(int i=1,x;i<=n;i++){//Find a[i]%4
		if(a[i])continue;
		if(mod[2][i]==0){
			cout<<"? 4 "<<pos[1]<<' '<<pos[2]<<' '<<pos[3]<<' '<<i<<endl,cin>>x;
			if(x)mod[4][i]=2;
			else mod[4][i]=0;
		}
		else {
			cout<<"? 4 "<<pos[1]<<' '<<pos[2]<<' '<<pos[4]<<' '<<i<<endl,cin>>x;
			if(x)mod[4][i]=1;
			else mod[4][i]=3;
		}
	}
	for(int i=1,x;i<=n;i++){//Find a[i]%8
		if(a[i])continue;
		if(mod[4][i]==0){
			cout<<"? 8 "<<pos[1]<<' '<<pos[2]<<' '<<pos[3]<<' '<<pos[n-3]<<' '<<pos[n-2]<<' '<<pos[n-1]<<' '<<pos[n]<<' '<<i<<endl;
			cin>>x;
			if(x)mod[8][i]=4*n%8;
			else mod[8][i]=4-4*n%8;
		}
		if(mod[4][i]==3){
			cout<<"? 8 "<<pos[1]<<' '<<pos[2]<<' '<<pos[4]<<' '<<pos[n-3]<<' '<<pos[n-2]<<' '<<pos[n-1]<<' '<<pos[n]<<' '<<i<<endl;
			cin>>x;
			if(x)mod[8][i]=(4*n+7)%8;
			else mod[8][i]=(4*n+3)%8;
		}
		if(mod[4][i]==2){
			cout<<"? 8 "<<pos[1]<<' '<<pos[3]<<' '<<pos[4]<<' '<<pos[n-3]<<' '<<pos[n-2]<<' '<<pos[n-1]<<' '<<pos[n]<<' '<<i<<endl;
			cin>>x;
			if(x)mod[8][i]=(4*n+6)%8;
			else mod[8][i]=(4*n+2)%8;
		}
		if(mod[4][i]==1){
			cout<<"? 8 "<<pos[2]<<' '<<pos[3]<<' '<<pos[4]<<' '<<pos[n-3]<<' '<<pos[n-2]<<' '<<pos[n-1]<<' '<<pos[n]<<' '<<i<<endl;
			cin>>x;
			if(x)mod[8][i]=(4*n+5)%8;
			else mod[8][i]=(4*n+1)%8;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i])continue;
		for(int j=1;j<=n;j++)if(j%3==mod[3][i]&&j%5==mod[5][i]&&j%7==mod[7][i]&&j%8==mod[8][i])a[i]=j;
	}
	if(a[1]*2>n)for(int i=1;i<=n;i++)a[i]=n-a[i]+1;
	cout<<"! ";
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	cout<<endl;
}