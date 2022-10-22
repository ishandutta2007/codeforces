/*
	Name: 
	Copyright: gwj's
	Author: GaryMr
	Date: 02/06/19 11:37
	Description: 
*/

/*######################################################################
	
	!
	
	dfs or bfs
	
	c[i]
	
	long long
	
	dp
	
	:AABAB
	 >=0
	
	double> printf("%lf")6%.16lf
	
	dpg
	n8
	
	find if(l>=b||r<=a) return 0x3f3f3f3f; if(r<=b&&l>=a) return tree[k];
	 
	 
	
	priority_queue<> q;   
	priority_queue<,vector<>, less<> > pq1;  // 	
	priority_queue<vector<>, greater<> > pq2; // 
	
	1<<int(ceil(log2(double(n))))
	or
	
	
	make_pair 
	
	: dp[i]=dp[i-1]*2-dp[last[i]-1]
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
//inline LL MY_POW(LL num,LL x){
//	LL res=1;
//	rb(i,1,x){
//		res*=num;
//	}
//	return num;
//}
int main(){
	LL k;//<=1e 12
	cin>>k;
	if(k<=9) printf("%I64d",k);
	else{
		if(k<=189){
			k-=9;
			LL num=9;
			num+=k/2;
			if(k%2) num++;
			k%=2;
			rb(i,1,k){
				num/=10;
			}
			printf("%d",num%10);
		}
		else{
			if(k<=2889){//san
				k-=189;
//				k-=9;
				LL num=99;
				num+=k/3;
			if(k%3) num++;
			k%=3;
			if(k==0) k=3;
			rb(i,1,(3-k)){
				num/=10;
			}
			printf("%d",num%10);
			}
			else{
				if(k<=38889){//four
			k-=2889;
//			k-=9;
			LL num=999;
			num+=k/4;
			if(k%4) num++;
			k%=4;
			if(k==0) k=4;
			rb(i,1,(4-k)){
				num/=10;
			}
			printf("%d",num%10);
				}
				else{
					if(k<=488889){//five
						k-=38889;
//			k-=9;
				LL num=9999;
			num+=k/5;
			if(k%5) num++;
			k%=5;
			if(k==0) k=5;
			rb(i,1,(5-k)){
				num/=10;
			}
			printf("%d",num%10);
					}
					else{
						if(k<=5888889){//six
						k-=488889;
//			k-=9;
				LL num=99999;
			num+=k/6;
			if(k%6) num++;
			k%=6;
			if(k==0) k=6;
			rb(i,1,(6-k)){
				num/=10;
			}
			printf("%d",num%10);
						}
						else{
							if(k<=68888889){//qi
														k-=5888889;
//			k-=9;
				LL num=999999;
			num+=k/7;
			if(k%7) num++;
			k%=7;
			if(k==0) k=7;
			rb(i,1,(7-k)){
				num/=10;
			}
			printf("%d",num%10);
							}
							else{
								if(k<=788888889){
										k-=68888889;
//			k-=9;
				LL num=9999999;
			num+=k/8;
			if(k%8) num++;
			k%=8;
			if(k==0) k=8;
			rb(i,1,(8-k)){
				num/=10;
			}
			printf("%d",num%10);
								}
								else{
									if(k<=8888888889){
										k-=788888889;
//			k-=9;
				LL num=99999999;
			num+=k/9;
			if(k%9) num++;
			k%=9;
			if(k==0) k=9;
			rb(i,1,(9-k)){
				num/=10;
			}
			printf("%d",num%10);
									}
									else{
										if(k<=98888888889){
																					k-=8888888889;
//			k-=9;
				LL num=999999999;
			num+=k/10;
			if(k%10) num++;
			k%=10;
			if(k==0) k=10;
			rb(i,1,(10-k)){
				num/=10;
			}
			printf("%d",num%10);
										}
										else{
											k-=98888888889;
	//			k-=9;
					LL num=9999999999;
					
					num+=k/11;//cout<<num<<endl;
					if(k%11) num++;
					k%=11;
					if(k==0) k=11;
//					cout<<k<<endl;
					rb(i,1,(11-k)){
						num/=10;
					}
					printf("%d",num%10);
										}
										
										//IMPOSSIBLE
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}