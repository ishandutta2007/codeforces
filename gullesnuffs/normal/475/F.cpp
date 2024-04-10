#include <bits/stdc++.h>

using namespace std;

struct Meta{
	set<pair<int, int> > x;
	set<pair<int, int> > y;
	queue<int> considerX, considerY;

	void add(int X, int Y){
		x.insert(make_pair(X, Y));
		y.insert(make_pair(Y, X));
		considerX.push(X-1);
		considerX.push(X+1);
		considerY.push(Y-1);
		considerY.push(Y+1);
	}

	void remove(int X, int Y){
		considerX.push(X);
		considerY.push(Y);
		x.erase(make_pair(X, Y));
		y.erase(make_pair(Y, X));
	}
};

queue<Meta*> q;
Meta mMeta;
int ans=1;
int inf=1500000000;

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		int x, y;
		scanf("%d%d", &x, &y);		
		mMeta.add(x, y);
	}
	q.push(&mMeta);
	while(!q.empty()){
		Meta* cur=q.front();
		q.pop();
		while(!cur->considerX.empty()){
			int x=cur->considerX.front();
			cur->considerX.pop();
			auto it=cur->x.lower_bound(make_pair(x, -inf));
			if(it == cur->x.end() || it == cur->x.begin())
				continue;
			if(it->first == x)
				continue;
			++ans;
			auto itb=it, itf=it;
			while(true){
				if(itb == cur->x.begin() || itf == cur->x.end())
					break;
				--itb;
				++itf;
			}
			Meta* newMeta = new Meta();
			if(itb == cur->x.begin()){
				while(it != cur->x.begin()){
					--it;
					newMeta->add(it->first, it->second);
				}
			}
			else{
				while(it != cur->x.end()){
					newMeta->add(it->first, it->second);
					++it;
				}
			}
			for(auto it2=newMeta->x.begin(); it2 != newMeta->x.end(); ++it2){
				cur->remove(it2->first, it2->second);
			}
			q.push(cur);
			q.push(newMeta);
		}
		while(!cur->considerY.empty()){
			int y=cur->considerY.front();
			cur->considerY.pop();
			auto it=cur->y.lower_bound(make_pair(y, -inf));
			if(it == cur->y.end() || it == cur->y.begin())
				continue;
			if(it->first == y)
				continue;
			++ans;
			auto itb=it, itf=it;
			while(true){
				if(itb == cur->y.begin() || itf == cur->y.end())
					break;
				--itb;
				++itf;
			}
			Meta* newMeta = new Meta();
			if(itb == cur->y.begin()){
				while(it != cur->y.begin()){
					--it;
					newMeta->add(it->second, it->first);
				}
			}
			else{
				while(it != cur->y.end()){
					newMeta->add(it->second, it->first);
					++it;
				}
			}
			for(auto it2=newMeta->x.begin(); it2 != newMeta->x.end(); ++it2){
				cur->remove(it2->first, it2->second);
			}
			q.push(cur);
			q.push(newMeta);
		}
	}
	printf("%d\n", ans);
}