#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std; 
int N,K;int ask(int x){cout<<"? "<<x<<endl;cin>>x;return x;}int Rand(){return (rand()<<15)|rand();}
int main(){cin>>N>>K;srand(time(0));while(1){int x=Rand()%N+1;if(ask(x)<K){while(ask(x)<K)x=x%N+1;cout<<"! "<<x<<endl;return 0;}}return 0;}