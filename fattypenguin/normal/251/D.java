import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class TaskDD implements Runnable {

    private void solve() throws IOException {
    	
    	int n = nextInt();
    	long a[] = new long[n];
    	long sum = 0l;
    	
    	for (int i = 0; i < n; ++i) {
    		a[i] = nextLong();
    		sum ^= a[i];
    	}
    	
    	Bitset equ[] = new Bitset[64];
    	int pos[] = new int[64];
    	
    	int equations = 0;
    	long anss = 0;

    	for (int i = 62; i >= 0; --i) {
    		
    		if ((sum & (1l << i)) != 0) {
    			continue;
    		}
    		
    		equ[equations] = new Bitset(n + 1);
    		for (int j = 0; j < n; ++j) {
    			if ((a[j] & (1l << i)) != 0) {
    				equ[equations].set(j, 1);
    			}
    		}
    		
    		equ[equations].set(n, 1);
    		
    		for (int j = 0; j < equations; ++j) {
    			if (equ[equations].get(pos[j]) == 1) {
    				equ[equations] = equ[equations].xor(equ[j]);
    			}
    		}
    		
    		int firstBit = 0;
    		while (firstBit < n && equ[equations].get(firstBit) == 0) {
    			++firstBit;
    		}
    		
    		if (firstBit < n) {
    			
    			for (int j = 0; j < equations; ++j) {
    				if (equ[j].get(firstBit) == 1) {
    					equ[j] = equ[j].xor(equ[equations]);
    				}
    			}
    			
    			pos[equations++] = firstBit;
    		}
    	}
    	
    	for (int i = 62; i >= 0; --i) {
    		
    		if ((sum & (1l << i)) == 0) {
    			continue;
    		}
    		
    		equ[equations] = new Bitset(n + 1);
    		for (int j = 0; j < n; ++j) {
    			if ((a[j] & (1l << i)) != 0) {
    				equ[equations].set(j, 1);
    			}
    		}

    		for (int j = 0; j < equations; ++j) {
    			if (equ[equations].get(pos[j]) == 1) {
    				equ[equations] = equ[equations].xor(equ[j]);
    			}
    		}
    		
    		int firstBit = 0;
    		while (firstBit < n && equ[equations].get(firstBit) == 0) {
    			++firstBit;
    		}
    		
    		if (firstBit < n) {
    			
    			for (int j = 0; j < equations; ++j) {
    				if (equ[j].get(firstBit) == 1) {
    					equ[j] = equ[j].xor(equ[equations]);
    				}
    			}
    			
    			pos[equations++] = firstBit;
    		}
    	}
    	
    	int ans[] = new int[n];
    	for (int i = 0; i < equations; ++i)
    		ans[pos[i]] = equ[i].get(n);
    	
    	for (int i = 0; i < n; ++i) {
    		
    		if (i != 0) {
    			writer.print(" ");
    		}
    		
    		if (ans[i] == 1) {
    			writer.print("1");
    		} else {
    			writer.print("2");
    		}
    	}
    	
    	writer.println();
    }

    public static void main(String[] args) {
        new TaskDD().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            writer = new PrintWriter(System.out);
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}

class Bitset {
	
	int len, vlen;
	int bit[];
	
	Bitset(int bits) {
		len = bits;
		vlen = (bits + 31) >> 5;
		bit = new int[vlen];
	}
	
	//a[x] = y
	public void set(int x, int y) {
		if (((bit[x >> 5] >>> (x & 31)) & 1) != y) {
			bit[x >> 5] ^= 1 << (x & 31);
		}
	}
	
	public int get(int x) {
		return (bit[x >> 5] >>> (x & 31)) & 1;
	}
	
	public Bitset xor(Bitset o) {
		
		Bitset ret = new Bitset(len);
		for (int i = 0; i < vlen; ++i) {
			ret.bit[i] = bit[i] ^ o.bit[i];
		}
		
		return ret;
	}
	
	public Bitset and(Bitset o) {
		
		Bitset ret = new Bitset(len);
		for (int i = 0; i < vlen; ++i) {
			ret.bit[i] = bit[i] & o.bit[i];
		}
		
		return ret;
	}
	
	public Bitset or(Bitset o) {
		
		Bitset ret = new Bitset(len);
		for (int i = 0; i < vlen; ++i) {
			ret.bit[i] = bit[i] | o.bit[i];
		}
		
		return ret;
	}
	
	public Bitset not() {
		
		Bitset ret = new Bitset(len);
		for (int i = 0; i < vlen; ++i) {
			ret.bit[i] = ~bit[i];
		}
		
		return ret;
	}
}