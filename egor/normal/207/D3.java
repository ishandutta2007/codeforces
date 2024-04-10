import java.util.NavigableSet;
import java.io.OutputStreamWriter;
import java.io.BufferedWriter;
import java.util.SortedSet;
import java.util.HashMap;
import java.util.Comparator;
import java.io.OutputStream;
import java.util.RandomAccess;
import java.io.PrintWriter;
import java.util.Random;
import java.util.AbstractList;
import java.io.Writer;
import java.util.Collection;
import java.util.List;
import java.util.Map;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Set;
import java.util.NoSuchElementException;
import java.math.BigInteger;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Egor Kulikov (egor@egork.net)
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {

	public void solve(int testNumber, InputReader in, OutputWriter out) {
		/*for (int i = 1; i <= 3; i++) {
			Counter<String> popular = new Counter<String>();
			for (int j = 1; j <= 50; j++) {
				String fileName = "d:/home/projects/algo/" + i + "/0";
				if (j < 10)
					fileName += "0";
				fileName += j + ".txt";
				try {
					in = new InputReader(new FileInputStream(fileName));
				} catch (FileNotFoundException e) {
					throw new RuntimeException(e);
				}
				Set<String> current = new HashSet<String>();
				while (!in.isExhausted()) {
					String word = in.readString();
					while (word.length() > 0 && !Character.isLetter(word.charAt(0)))
						word = word.substring(1);
					while (word.length() > 0 && !Character.isLetter(word.charAt(word.length() - 1)))
						word = word.substring(0, word.length() - 1);
					if (word.length() <= 4)
						continue;
					current.add(word.toLowerCase());
				}
				for (String word : current)
					popular.add(word);
			}
			Map.Entry<String, Long>[] array = (Map.Entry<String, Long>[]) popular.entrySet().toArray(new Map.Entry[popular.size()]);
			Arrays.sort(array, new Comparator<Map.Entry<String, Long>>() {
				public int compare(Map.Entry<String, Long> o1, Map.Entry<String, Long> o2) {
					return Long.signum(o2.getValue() - o1.getValue());
				}
			});
			StringBuilder key = new StringBuilder("keys[" + i + "] = new String[]{");
			StringBuilder value = new StringBuilder("values[" + i + "] = new int[]{");
			int cnt = 0;
			for (Map.Entry<String, Long> anArray : array) {
				cnt++;
				if (cnt > 100)
					break;
				key.append("\"" + anArray.getKey() + "\", ");
				value.append(anArray.getValue() + ", ");
			}
			key.append("};");
			value.append("};");
			out.printLine(key);
			out.printLine(value);
		}*/
		String[][] keys = new String[4][];
		int[][] values = new int[4][];
		keys[1] = new String[]{"march", "market", "dollar", "money", "exchange", "billion", "treasury", "currency", "today", "would", "which", "around", "london", "their", "england", "central", "foreign", "assistance", "currencies", "against", "bills", "trading", "system", "rates", "liquidity", "while", "dealers", "house", "shortage", "after", "economic", "early", "financial", "official", "japan", "about", "monetary", "other", "recent", "these", "markets", "since", "forecast", "before", "could", "still", "provided", "april", "given", "among", "major", "reuters", "states", "federal", "intervention", "banks", "funds", "washington", "trade", "reserve", "secretary", "during", "bought", "morning", "finance", "paris", "because", "target", "total", "government", "further", "meeting", "committee", "month", "dollars", "account", "tokyo", "banking", "estimate", "james", "united", "continue", "president", "transactions", "revised", "nations", "agreement", "interest", "demand", "deficit", "sources", "current", "securities", "houses", "discount", "should", "baker", "treasury's", "domestic", "compared", };
		values[1] = new int[]{46, 32, 23, 22, 21, 21, 20, 19, 19, 18, 17, 15, 15, 14, 14, 14, 14, 13, 13, 13, 12, 12, 12, 12, 11, 11, 11, 11, 11, 11, 10, 10, 10, 10, 10, 10, 10, 10, 10, 9, 9, 9, 9, 9, 9, 9, 9, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 5, };
		keys[2] = new String[]{"billion", "march", "money", "supply", "reserve", "february", "growth", "compared", "january", "federal", "december", "rises", "banks", "previous", "ended", "deposits", "which", "business", "central", "adjusted", "monetary", "deposit", "increase", "seasonally", "loans", "year-on-year", "april", "major", "interest", "against", "circulation", "statement", "after", "while", "latest", "average", "government", "earlier", "washington", "currency", "revised", "treasury", "reuters", "balances", "total", "notes", "month", "figures", "other", "provisional", "including", "measure", "there", "savings", "accounts", "increased", "balance", "showed", "assets", "foreign", "liquidity", "daily", "rates", "period", "excluding", "funds", "dollar", "level", "november", "issued", "economists", "falls", "about", "outstanding", "budget", "sector", "three", "market", "public", "short", "reserves", "non-bank", "totaled", "quarter", "lending", "deficit", "range", "moving", "would", "securities", "operating", "prior", "unchanged", "liquid", "banking", "books", "defined", "acceptances", "personal", "weeks", };
		values[2] = new int[]{46, 38, 35, 30, 24, 20, 19, 18, 18, 18, 16, 16, 15, 15, 14, 14, 13, 12, 12, 12, 12, 11, 11, 11, 11, 10, 10, 10, 10, 10, 10, 10, 10, 9, 9, 9, 9, 9, 9, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, };
		keys[3] = new String[]{"march", "trade", "washington", "would", "japan", "states", "japanese", "united", "agreement", "officials", "against", "goods", "president", "official", "reagan", "tariffs", "foreign", "countries", "their", "tokyo", "government", "which", "semiconductor", "could", "billion", "about", "minister", "japan's", "april", "imports", "market", "markets", "exports", "house", "action", "after", "impose", "prime", "semiconductors", "retaliation", "likely", "other", "under", "dispute", "domestic", "electronic", "american", "failure", "world", "industry", "because", "congress", "talks", "sanctions", "international", "alleged", "computer", "there", "products", "added", "reuters", "economic", "announced", "plans", "expected", "while", "policy", "dumping", "before", "surplus", "secretary", "being", "nakasone", "major", "bilateral", "sources", "issue", "visit", "today", "growing", "white", "ministry", "microchips", "deficit", "yasuhiro", "yesterday", "council", "issues", "increase", "reporters", "first", "signed", "european", "decision", "joint", "although", "chips", "early", "already", "senior", };
		values[3] = new int[]{49, 49, 36, 35, 33, 30, 30, 29, 25, 24, 24, 24, 22, 22, 22, 22, 21, 21, 21, 20, 20, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 17, 17, 17, 16, 16, 15, 15, 15, 15, 15, 15, 14, 14, 14, 14, 14, 14, 13, 13, 13, 13, 13, 13, 13, 13, 12, 12, 12, 12, 12, 12, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 9, 9, 9, 9, 9, 9, 9, 8, 8, 8, 8, 8, 8, 8, 8, };
		Map<String, Integer>[] maps = new Map[4];
		int[] score = new int[4];
		for (int i = 1; i <= 3; i++) {
			maps[i] = new CPPMap<String, Integer>(new Factory<Integer>() {
				public Integer create() {
					return 0;
				}
			});
			for (int j = 0; j < keys[i].length; j++)
				maps[i].put(keys[i][j], values[i][j]);
		}
		while (!in.isExhausted()) {
			String word = in.readString();
			while (word.length() > 0 && !Character.isLetter(word.charAt(0)))
				word = word.substring(1);
			while (word.length() > 0 && !Character.isLetter(word.charAt(word.length() - 1)))
				word = word.substring(0, word.length() - 1);
			if (word.length() <= 4)
				continue;
			for (int i = 1; i <= 3; i++)
				score[i] += maps[i].get(word);
		}
		int answer = ListUtils.maxIndex(Array.wrap(score));
		out.printLine(answer);
	}
}

class InputReader {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;

	public InputReader(InputStream stream) {
		this.stream = stream;
	}

	public int read() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}

	public int peek() {
		if (numChars == -1)
			return -1;
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				return -1;
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar];
	}

	public String readString() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuffer res = new StringBuffer();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	public static boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public boolean isExhausted() {
		int value;
		while (isSpaceChar(value = peek()) && value != -1)
			read();
		return value == -1;
	}

	}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}

	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}

	public void print(Object...objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}

	public void printLine(Object...objects) {
		print(objects);
		writer.println();
	}

	public void close() {
		writer.close();
	}

	}

class CPPMap<K, V> extends HashMap<K, V> {
	private final Factory<V> defaultValueFactory;

	public CPPMap(Factory<V> defaultValueFactory) {
		this.defaultValueFactory = defaultValueFactory;
	}

	public V get(Object key) {
		if (containsKey(key))
			return super.get(key);
		V value = defaultValueFactory.create();
		try {
			//noinspection unchecked
			super.put((K) key, value);
			return value;
		} catch (ClassCastException e) {
			return value;
		}
	}
}

interface Factory<V> {
	public V create();
}

class ListUtils {
	public static<T> int find(List<T> sequence, T value) {
		int size = sequence.size();
		for (int i = 0; i < size; i++) {
			if (MiscUtils.equals(sequence.get(i), value))
				return i;
		}
		return size;
	}

	public static<T extends Comparable<T>> int maxIndex(List<T> sequence) {
		return find(sequence, CollectionUtils.maxElement(sequence));
	}

	}

abstract class Array<T> extends AbstractList<T> implements RandomAccess {

	public static List<Integer> wrap(int...array) {
		return new IntArray(array);
	}

	protected static class IntArray extends Array<Integer> {
		protected final int[] array;

		protected IntArray(int[] array) {
			this.array = array;
		}

		public int size() {
			return array.length;
		}

		public Integer get(int index) {
			return array[index];
		}

		public Integer set(int index, Integer value) {
			int result = array[index];
			array[index] = value;
			return result;
		}
	}

	}

class MiscUtils {

	public static<T> boolean equals(T first, T second) {
		return first == null && second == null || first != null && first.equals(second);
	}

	}

class CollectionUtils {

	public static<T extends Comparable<T>> T maxElement(Iterable<T> collection) {
		T result = null;
		for (T element : collection) {
			if (result == null || result.compareTo(element) < 0)
				result = element;
		}
		return result;
	}

	}