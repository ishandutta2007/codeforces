#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll


const int N=(int)1e5+7;
int n;
int a[N];
int sumofguys[N],ord[N];
vector<int> guys[N];
int ok[N];
int oklft[N];
int okrgh[N];
int where[N];

bool cmp(int i,int j){
  return sumofguys[i]*((int)guys[j].size())>sumofguys[j]*((int)guys[i].size());
}

bool match(int teacher,int child){
  child-=n;
  assert(1<=teacher&&teacher<=n);
  assert(1<=child&&child<=n);
  return (a[teacher]*((int)guys[child].size())>=sumofguys[child]);
}

bool allok(int l,int r){
  if(l>r)return 1;
  assert(1<=l&&l<=r&&r<=n);
  return ok[r]-ok[l-1]==r-l+1;
}

bool alloklft(int l,int r){
  if(l>r)return 1;
  assert(2<=l&&l<=r&&r<=n);
  return oklft[r]-oklft[l-1]==r-l+1;
}

bool allokrgh(int l,int r){
  if(l>r)return 1;
  assert(1<=l&&l<=r&&r<n);
  return okrgh[r]-okrgh[l-1]==r-l+1;
}

int getid(int pos,int skip){
  assert(1<=pos&&pos<n);
  if (pos<skip){
    return pos;
  }
  return pos+1;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);

  int t;
  cin>>t;
  while (t--){
    {
      int tch;
      cin>>tch>>n;
      assert(tch>=n);
      for (int i=1;i<=tch;i++){
        cin>>a[i];
      }
      sort(a+1,a+tch+1);
      reverse(a+1,a+tch+1);
    }
    int total=0;
    for (int i=1;i<=n;i++){
      int l;
      cin>>l;
      guys[i].resize(l);
      sumofguys[i]=0;
      for (auto &x:guys[i]){
        cin>>x;
        sumofguys[i]+=x;
      }
      total+=l;
      ord[i]=i;
    }
    sort(ord+1,ord+n+1,cmp);
    for (int i=1;i<=n;i++){
      where[ord[i]]=i;
    }

    for (int i=1;i<=n;i++){
      ok[i]=oklft[i]=okrgh[i]=0;
    }


    for (int i=1;i<=n;i++){
      ok[i]=match(i,ord[i]+n);
      if (i>=2){
        oklft[i]=match(i-1,ord[i]+n);
      }
      if(i<n){
        okrgh[i]=match(i+1,ord[i]+n);
      }
    }


    for (int i=1;i<=n;i++) {
      ok[i]+=ok[i-1];
      oklft[i]+=oklft[i-1];
      okrgh[i]+=okrgh[i-1];
    }


    vector<int>sol;

    for (int it=1;it<=n;it++){
      for (auto &guy:guys[it]) {
        int nwsum=sumofguys[it]-guy;
        int nwlen=(int)guys[it].size()-1;

        int i=where[it];
        /// find it's position = find how many it is smaller than

        int low=1,high=n-1,cnt=0;
        while (low<=high) {
          int mid=(low+high)/2;
          int j=ord[getid(mid,i)];
          assert(it!=j);
          if ((int)guys[j].size()*nwsum<=sumofguys[j]*nwlen) {
            cnt=mid;
            low=mid+1;
          }else{
            high=mid-1;
          }
        }
        int j=cnt+1;
        assert(1<=j&&j<=n);

        bool isgood=1;

        if(j>=i){

          isgood&=allok(1,i-1);
          isgood&=allok(j+1,n);
          isgood&=alloklft(i+1,j);
          isgood&=(nwsum<=a[j]*nwlen);
        }else{
          isgood&=allok(1,j-1);
          isgood&=allok(i+1,n);
          isgood&=allokrgh(j,i-1);
          isgood&=(nwsum<=a[j]*nwlen);
        }
        sol.push_back(isgood);
      }
    }

    assert((int)sol.size()==total);
    for (auto &x:sol){

      assert(x!=-1);
      if(x==-1){
        cout<<"?";
        continue;
      }
      cout<<x;
    }
    cout<<"\n";
    continue;
    {
      int zm=0;
      for (int i=1;i<=n;i++){
        zm+=(int)guys[i].size();
      }
      for (int i=1;i<=n;i++){
        cout<<a[i]<<" ";
      }
      cout<<" : "<<zm<<"\n";
    }
  }

  return 0;
}