#include<bits/stdc++.h>
using namespace std;
char f(int i){
	if(i<10){
		return (char)(i+48);
	}else if(i<36){
		return (char)(i-10+65);
	}else{
		return (char)(i-36+97);
	}
}
int main (){
	int x;
	int a[62];
	for(int i=0;i<62;i++){
		a[i]=0;
	}
	cin>>x;
	for(int i=0;i<x;i++){
		char c;
		cin>>c;
		if((int)(c)<58){
			a[(int)(c-48)]++;
		}else if((int)(c)<93){
			a[(int)(c-65)+10]++;
		}else{
			a[(int)(c-97)+10+26]++;
		}
	}
	vector<int> v;
	for(int i=1;i<=sqrt(x);i++){
		if(x%i==0){
			v.push_back(i);
			if(i*i!=x){
			v.push_back(x/i);
		}
		}
	}
//	cout<<v.size()<<endl;
	int odd=0;
	for(int i=0;i<62;i++){
		if(a[i]%2==1){
		//	cout<<i<<endl;
			odd++;
		}
	}
	sort(v.begin(),v.end());
		int num;
		int s;
	for(int i=0;i<v.size();i++){
		 num=v[i];
	//	cout<<num<<endl;
		 s=x/num;
		if(s%2==0&&odd==0){
			break;
		}else if(s%2==1&&odd<=num){
			break;
		}
	}
	cout<<num<<endl;
	for(int i=0;i<num;i++){
		int pointer=0;
		deque<char> d;
		if(s%2==1){
			for(int j=0;j<62;j++){
				if(odd==0&&a[j]>0){
					a[j]--;
					d.push_back(f(j));
					break;
				}
				
				if(a[j]%2==1){
					odd--;
					a[j]--;
					d.push_back(f(j));
					break;
					
				}
			}
		}
		for(int j=0;j<62;j++){
			while(d.size()<s&&a[j]>=2){
				a[j]-=2;
				d.push_front(f(j));
				d.push_back(f(j));
			}
		}
		
		while(d.size()!=0){
			cout<<d.front();
			d.pop_front();
			
		}
		if(i==num-1){
			cout<<endl;
		}else{
			cout<<" ";
		}
	}
}