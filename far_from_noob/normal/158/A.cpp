#include <iostream>
using namespace std;

int main() {
	int n,k;
	cin >> n>>k;
	int a[n];
	for(int i=0;i<n;i++){
	    cin >> a[i];
	}
	int temp=a[k-1],count=0;
	for(int i=k;i<n;i++)
	{
	    if(a[i]==temp)
	    count++;
	    else break;
	}
	int count1=0;
	for(count1=0;count1<k+count;count1++){
	    if(a[count1]>0)
	    ;
	    else break;
	}
	cout << count1;
	return 0;
}