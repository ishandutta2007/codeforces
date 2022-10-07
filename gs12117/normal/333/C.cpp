#include<stdio.h>
#include<set>
int n,m;
std::set<int> a;
std::set<int> xd[4];
std::set<int> calc(int val,int dgt){
	std::set<int> res;
	res.insert(val);
	res.insert(-val);
	if(dgt==1){
		xd[1]=res;
		return res;
	}
	std::set<int>::iterator ite;
	std::set<int> x=calc(val/10,dgt-1);
	for(ite=x.begin();ite!=x.end();ite++){
		res.insert((*ite)+(val%10));
		res.insert((*ite)-(val%10));
		res.insert((*ite)*(val%10));
	}
	if(dgt==2){
		xd[2]=res;
		return res;
	}
	x=xd[dgt-2];
	for(ite=x.begin();ite!=x.end();ite++){
		res.insert((*ite)+(val%100));
		res.insert((*ite)-(val%100));
		res.insert((*ite)*(val%100));
	}
	if(dgt==3){
		xd[3]=res;
		return res;
	}
	x=xd[dgt-3];
	for(ite=x.begin();ite!=x.end();ite++){
		res.insert((*ite)+(val%1000));
		res.insert((*ite)-(val%1000));
		res.insert((*ite)*(val%1000));
	}
	return res;
}
int main(){
	int i,j;
	std::set<int>::iterator ite;
	scanf("%d%d",&n,&m);
	for(i=0;i<10000;i++){
		std::set<int>x=calc(i,4);
		for(ite=x.begin();ite!=x.end();ite++){
			if(n-(*ite)>=0&&n-(*ite)<10000){
				a.insert(i*10000+n-(*ite));
			}
		}
		if(a.size()>=m)break;
	}
	ite=a.begin();
	for(i=0;i<m;i++){
		printf("%08d\n",*ite);
		ite++;
	}
}