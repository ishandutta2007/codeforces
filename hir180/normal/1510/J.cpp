#include <bits/stdc++.h>
#define SIZE 100005
using namespace std;

char str[SIZE];
int cnt[SIZE];
void print(vector <int> vec){
	printf("%d\n",vec.size());
	for(int i=0;i<vec.size();i++){
		if(i!=0) printf(" ");
		printf("%d",vec[i]);
	}puts("");
}
int main(){
	scanf("%s",&str);
	int n=strlen(str);
	int bef=-2;
	for(int i=0;i<n;i++){
		if(str[i]=='#'){
			if(bef!=i-1){
				int L=i-bef-1;
				cnt[L]++;
			}
			bef=i;
		}
	}
	if(bef==-2){
		puts("0");
		return 0;
	}
	cnt[(n+1)-bef-1]++;
	//for(int i=1;i<=n;i++) printf("%d ",cnt[i]);puts("");
	for(int w=0;w<=n;w++){
		if(cnt[w]>0) break;
		if(w==0){
			bool up=true;
			for(int i=2;i<=n;i++){
				if(cnt[i]>0) up=false;
			}
			if(up){
				vector <int> vec;
				int f=0;
				for(int i=0;i<n;i++){
					if(str[i]=='_'){
						vec.push_back(f);
						f=0;
					} else f++;
				}
				vec.push_back(f);
				print(vec);
				return 0;
			}
		} else if(w==1){
			bool up=true;
			for(int i=w+2;i<=n;i+=2){
				if(cnt[i]>0) up=false;
			}
			if(up){
				vector <int> vec;
				int bef=-2;
				int nm=0;
				for(int i=0;i<n;i++){
					if(str[i]=='#'){
						if(bef==i-1) nm++;
						else{
							if(nm>0) vec.push_back(nm+w);
							nm=1;
							int l=bef+2,r=i-w-1;
							while(l<r){
								vec.push_back(1);
								l+=2;
							}
						}
						bef=i;
					}
				}
				vec.push_back(nm+w);
				int l=bef+2,r=(n+1)-w-1;
				while(l<r){
					vec.push_back(1);
					l+=2;
				}
				print(vec);
				return 0;
			}
		} else if(cnt[w+2]==0){
			vector <int> vec;
			int bef=-2;
			int nm=0;
			for(int i=0;i<n;i++){
				if(str[i]=='#'){
					if(bef==i-1) nm++;
					else{
						if(nm>0) vec.push_back(nm+w);
						nm=1;
						int l=bef+2,r=i-w-1;
						while(l<r){
							if(l!=r-2) vec.push_back(1);
							else vec.push_back(2);
							l+=2;
						}
					}
					bef=i;
				}
			}
			vec.push_back(nm+w);
			int l=bef+2,r=(n+1)-w-1;
			while(l<r){
				if(l!=r-2) vec.push_back(1);
				else vec.push_back(2);
				l+=2;
			}
			print(vec);
			return 0;
		}
	}
	puts("-1");
}