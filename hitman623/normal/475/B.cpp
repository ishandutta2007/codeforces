#include <iostream>
using namespace std;
int main()
{
    long n,m;
    char rdir[20],cdir[20];
    cin>>n>>m;
	cin>>rdir>>cdir;
	if(rdir[0]!=rdir[n-1] && cdir[0]!=cdir[m-1] && ((rdir[0]=='>' && cdir[0]=='^' ) || (rdir[0]=='<' && cdir[0]=='v' )))
    cout<<"YES";
    else cout<<"NO";
    return 0;
}