import java.io.PrintWriter;
import java.util.Scanner;

/**
 * @author Egor Kulikov (kulikov@devexperts.com)
 */
public class Memory implements Runnable {
	private Scanner in = new Scanner(System.in);
	private PrintWriter out = new PrintWriter(System.out);
	private int t, m;

	public static void main(String[] args) {
		new Thread(new Memory()).start();
	}

	private void read() {
		t = in.nextInt();
		m = in.nextInt();
	}

	private void solve() {
		int numAllocated = 0;
		int[] mem = new int[m];
		for (int i = 0; i < t; i++) {
			String c = in.next();
			if (c.equals("alloc")) {
				int l = in.nextInt();
				boolean found = false;
				for (int j = 0; j <= m - l; j++) {
					boolean good = true;
					for (int k = j; k < j + l; k++) {
						if (mem[k] != 0) {
							good = false;
							break;
						}
					}
					if (good) {
						++numAllocated;
						for (int k = j; k < j + l; k++)
							mem[k] = numAllocated;
						found = true;
						out.println(numAllocated);
						break;
					}
				}
				if (!found)
					out.println("NULL");
			} else if (c.equals("erase")) {
				int x = in.nextInt();
				boolean found = false;
				for (int j = 0; j < m; j++) {
					if (mem[j] == x) {
						mem[j] = 0;
						found = true;
					}
				}
				if (!found || x == 0)
					out.println("ILLEGAL_ERASE_ARGUMENT");
			} else {
				int[] memcpy = new int[m];
				int ind = 0;
				for (int j = 0; j < m; j++) {
					if (mem[j] != 0)
						memcpy[ind++] = mem[j];
				}
				mem = memcpy;
			}
		}
	}

	private void write() {
	}

	public void run() {
		read();
		solve();
		write();
		out.close();
	}
}