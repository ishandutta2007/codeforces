/*
	*#*#*#* Author GaryMr *#*#*#*
########################################################################
	
	
	c[i]
	
	long long
	
	dp
	
	 >=0
	
	dpg
	n8
	
	find if(l>=b||r<=a) return 0x3f3f3f3f; if(r<=b&&l>=a) return tree[k];
	 
	 
	
	priority_queue<> q;   
	priority_queue<,vector<>, less<> > pq1;  // 	
	priority_queue<vector<>, greater<> > pq2; // 
	
	1<<ceil(log2(double(n)))
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
#define niv vector<int>
#define IT iterator
#define FIR first
#define SEC second
using namespace std;
const int MAX=0x3f3f3f3f;
typedef pair<int,int> mp;map<char,int> m;
typedef pair<mp,mp> superpair;
int main(){
	int T;
	scanf("%d",&T);
	rb(k,1,T){
		m.clear();
		char c[105];
		int tot=0;
		string s;
		cin>>s;
		int len=s.length();
		if(len==1){
			cout<<s<<endl;
			continue;
		}
		rb(i,0,len-1){
			m[s[i]]++;
			if(m[s[i]]>1) continue;
			c[++tot]=s[i];
		}
		sort(c+1,c+1+tot);
		if(tot==1){
			cout<<s<<endl;
			continue;
		}
		if(tot==2&&c[1]==c[2]-1){
			cout<<"No answer"<<endl;
			continue;
		}
		if(tot==2){
			rb(i,1,m[c[1]]) printf("%c",c[1]);
			rb(i,1,m[c[2]]) printf("%c",c[2]);
			printf("\n");
			continue;
		}
		if(tot==3&&c[1]==c[2]-1&&c[2]==c[3]-1){
			cout<<"No answer"<<endl;
			continue;
		}
		if(tot==3){
			if(c[1]!=c[2]-1){
				rb(j,1,m[c[2]]){
					printf("%c",c[2]);
				}
				rb(j,1,m[c[1]]){
					printf("%c",c[1]);
				}
				rb(j,1,m[c[3]]){
					printf("%c",c[3]);
				}
			}
			else{
				rb(j,1,m[c[2]]){
					printf("%c",c[2]);
				}
				rb(j,1,m[c[3]]){
					printf("%c",c[3]);
				}
				rb(j,1,m[c[1]]){
					printf("%c",c[1]);
				}
				
			}printf("\n");
			continue;
		}
		if(tot==4){
//			return 0;
				rb(j,1,m[c[3]]){
					printf("%c",c[3]);
				}
				rb(j,1,m[c[1]]){//return 0;
//					cout<<j<<endl;
					printf("%c",c[1]);
				}
				rb(j,1,m[c[4]]){
					printf("%c",c[4]);
				}
				rb(j,1,m[c[2]]){
					printf("%c",c[2]);
				}printf("\n");continue;
		}
//		int mid=tot/2+1;
//		int one=1,two=mid;
		for(int i=1;i<=tot;i+=2){
			rb(j,1,m[c[i]]){
				printf("%c",c[i]);
			}
		}
		for(int j=2;j<=tot;j+=2){
			rb(k,1,m[c[j]]){
				printf("%c",c[j]);
			}
		}
		printf("\n");
	}
	return 0;
}