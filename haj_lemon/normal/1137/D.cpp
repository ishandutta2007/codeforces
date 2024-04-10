#include<bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
int s,sum,ns,be[10],no;
string st;
int main(){
	while (1){
		sum+=2;
		cout<<"next 0 1"<<endl;
		fflush(stdout);
		cin>>s;
		for (int i=1;i<=s;i++) cin>>st;
		cout<<"next 1"<<endl;
		fflush(stdout);
		cin>>s;
		for (int i=1;i<=s;i++) cin>>st;
		if (s==2)break;
	}
	while (1){
		cout<<"next 2 0"<<endl;
		fflush(stdout);
		cin>>s;
		bool c1=0,c2=0;
		for (int i=1;i<=s;i++){
			cin>>st;
			int l=st.length();
			bool v1=0,v2=0,v3=0;
			for (int i=0;i<l;i++){if (st[i]=='0') v1=1;if (st[i]=='1') v2=1;if (st[i]=='2')v3=1;}
			if (v1&&v2) c1=1;
			if ((v1|v2)&&v3){
				if (v1) be[0]=2;
				if (v2) be[1]=2;
				c2=1;
			}
		}
		no++;
		if (c1){ns=no;break;}
		if (c2){ns=sum/2;break;}
	}
	while (no<ns){
		no++;
		cout<<"next 2";
		for (int i=0;i<=1;i++) if (be[i]==2)cout<<' '<<i;cout<<endl;
		fflush(stdout);
		cin>>s;
		for (int i=1;i<=s;i++){
			cin>>st;
			bool v1=0,v2=0,v3=0;
			for (int i=0;i<st.length();i++){if (st[i]=='0') v1=1;if (st[i]=='1') v2=1;if (st[i]=='2')v3=1;}
			if ((v1|v2)&&v3){
				if (v1) be[0]=2;
				if (v2) be[1]=2;
			}
		}
	}
	while (1){
		cout<<"next";
		for (int i=2;i<=9;i++) cout<<' '<<i;
		for (int i=0;i<=1;i++) if (be[i]==2) cout<<' '<<i;cout<<endl;
		fflush(stdout);
		cin>>s;
		if (s==1){
			puts("done");
			return 0;
		}else{
			for (int i=1;i<=s;i++){
				cin>>st;
				bool v1=0,v2=0,v3=0;
				for (int i=0;i<st.length();i++){if (st[i]=='0') v1=1;if (st[i]=='1') v2=1;if (st[i]=='2')v3=1;}
				if ((v1|v2)&&v3){
					if (v1) be[0]=2;
					if (v2) be[1]=2;
				}
			}
		}
	}
	return 0;
}