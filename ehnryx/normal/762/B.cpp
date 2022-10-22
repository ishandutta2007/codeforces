#include <bits/stdc++.h>
using namespace std;

int min(int a, int b) {
	return (a < b) ? a : b;
}

int main() {
	int compusb, compps2, compboth;
	char type[7];
	vector<int> usb;
	vector<int> ps2;
	cin >> compusb >> compps2 >> compboth;
	int mouses, price;
	cin >> mouses;
	while (mouses--) {
		cin >> price;
		scanf("%s", type);
		if (strcmp(type,"USB") == 0)
			usb.push_back(price);
		else
			ps2.push_back(price);
	}
	
	sort(usb.begin(), usb.end());
	sort(ps2.begin(), ps2.end());
	long long cost = 0;
	int usbpos, ps2pos;
	for (usbpos = 0; usbpos < min(compusb, usb.size()); usbpos++) 
		cost += usb[usbpos];
	for (ps2pos = 0; ps2pos < min(compps2, ps2.size()); ps2pos++)
		cost += ps2[ps2pos];
	int iu = usbpos;
	int ip = ps2pos;
	while (usbpos - iu + ps2pos - ip < compboth) {
		if (usbpos < usb.size() && ps2pos < ps2.size()) {
			if (usb[usbpos] < ps2[ps2pos])
				cost += usb[usbpos++];
			else 
				cost += ps2[ps2pos++];
		}
		else if (usbpos < usb.size()) {
			cost += usb[usbpos++];
		}
		else if (ps2pos < ps2.size()) {
			cost += ps2[ps2pos++];
		}
		else 
			break;
	}
	cout << usbpos + ps2pos << " " << cost << endl;

	return 0;
}